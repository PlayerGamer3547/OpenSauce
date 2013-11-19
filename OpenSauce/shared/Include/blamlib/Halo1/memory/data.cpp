/*
	Yelo: Open Sauce SDK

	See license\OpenSauce\OpenSauce for specific license information
*/
#include "Common/Precompile.hpp"
#include <blamlib/Halo1/memory/data.hpp>

#if PLATFORM_IS_EDITOR
	#include "Engine/EngineFunctions.hpp"
#endif

static const Yelo::datum_index::salt_t k_datum_index_salt_msb = 
	1U << 
	(BIT_COUNT(Yelo::datum_index::salt_t) - 1);

namespace Yelo
{
	namespace Memory
	{
		datum_index::salt_t s_data_array::GetInitialSalt() const
		{
			datum_index::salt_t result = 0;
			// NOTE: engine uses strncpy
			std::memcpy(&result, this->name, sizeof(result));

			result |= k_datum_index_salt_msb;

			return result;
		}
		datum_index::salt_t s_data_array::GetNextSalt(datum_index::salt_t cursor) const
		{
			return ++cursor != 0 
				? cursor
				: k_datum_index_salt_msb;
		}

		bool s_data_iterator::operator!=(const s_data_iterator& other) const
		{
			auto last_datum = this->data->last_datum;

			if (other.IsEndHack())
				return !this->finished_flag;
			else if (this->IsEndHack())
				return !other.finished_flag;

			return this->index != other.index;
		}
	};

	namespace blam
	{
		using namespace Yelo::Memory;

#if !PLATFORM_IS_EDITOR
		void PLATFORM_API data_verify(const s_data_array* data)
		{
		}

		void PLATFORM_API data_make_valid(s_data_array* data)
		{
			data_verify(data);
			data->is_valid = true;
			data_delete_all(data);
		}
#endif

		void PLATFORM_API data_make_invalid(s_data_array* data)
		{
			data_verify(data);
			data->is_valid = false;
		}

		void PLATFORM_API data_iterator_new(s_data_iterator& iterator, s_data_array* data)
		{
			data_verify(data);
			ASSERT(data->is_valid, "invalid data array passed to " __FUNCTION__);

			iterator.data = data;
			iterator.next_index = 0;
			iterator.finished_flag = FALSE;
			iterator.index = datum_index::null;
			iterator.signature = CAST_PTR(uintptr_t, data) ^ Enums::k_data_iterator_signature;
		}

		void* PLATFORM_API data_iterator_next(s_data_iterator& iterator)
		{
#if PLATFORM_IS_EDITOR
			YELO_ASSERT_DISPLAY(iterator.signature == (CAST_PTR(uintptr_t, iterator.data) ^ Enums::k_data_iterator_signature),
				"uninitialized iterator passed to " __FUNCTION__);
#endif

			const s_data_array* data = iterator.data;
			data_verify(data);

#if PLATFORM_IS_EDITOR
			YELO_ASSERT_DISPLAY(data->is_valid, "tried to iterate %s when it was in an invalid state",
				data->name);
#endif

			datum_index::index_t absolute_index = iterator.next_index;
			int32 datum_size = data->datum_size;
			byte* pointer = CAST_PTR(byte*, data->base_address) + (datum_size * absolute_index);

			for (int16 last_datum = data->last_datum; absolute_index < last_datum; pointer += datum_size)
			{
				auto datum = CAST_PTR(const s_datum_base*, pointer);
				absolute_index++;

				if (!datum->IsNull())
				{
					iterator.next_index = absolute_index;
					iterator.index = datum_index::Create(absolute_index, datum->GetHeader());
					return pointer;
				}
				assert(absolute_index < data->max_datum);
			}
			assert(absolute_index == data->last_datum);
			iterator.next_index = absolute_index; // will equal last_datum at this point
			iterator.finished_flag = TRUE;
			iterator.index = datum_index::null;
			return nullptr;
		}
	};
};