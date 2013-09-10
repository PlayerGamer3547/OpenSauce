/*
	Yelo: Open Sauce SDK

	See license\OpenSauce\OpenSauce for specific license information
*/
#pragma once

#include <blamlib/memory/byte_swapping_base.hpp>
#include <blamlib/tag_files/tag_groups_base.hpp>

namespace Yelo
{
	namespace Enums
	{
		enum {
			k_maximum_field_byte_swap_codes = 1024,

			k_tag_field_scan_stack_size = 16,

			k_tag_block_format_buffer_size = 512,
		};
		enum field_type : _enum
		{
			_field_string,
			_field_char_integer,
			_field_short_integer,
			_field_long_integer,
			_field_angle,
			_field_tag,
			_field_enum,
			_field_long_flags,
			_field_word_flags,
			_field_byte_flags,
			_field_point_2d,
			_field_rectangle_2d,
			_field_rgb_color,
			_field_argb_color,
			_field_real,
			_field_real_fraction,
			_field_real_point_2d,
			_field_real_point_3d,
			_field_real_vector_2d,
			_field_real_vector_3d,
			_field_real_quaternion,
			_field_real_euler_angles_2d,
			_field_real_euler_angles_3d,
			_field_real_plane_2d,
			_field_real_plane_3d,
			_field_real_rgb_color,
			_field_real_argb_color,
			_field_real_hsv_color,
			_field_real_ahsv_color,
			_field_short_bounds,
			_field_angle_bounds,
			_field_real_bounds,
			_field_real_fraction_bounds,
			_field_tag_reference,
			_field_block,
			_field_short_block_index,
			_field_long_block_index,
			_field_data,
			_field_array_start,
			_field_array_end,
			_field_pad,
			_field_skip,
			_field_explanation,
			_field_custom,
			_field_terminator,

			k_number_of_tag_field_types,
		};

		// Note: AFAICT, the engine code doesn't actually do the postprocess setup this way.
		// They have what is essentially a boolean parameter that could be considered as 'bool for_editor'
		enum tag_postprocess_mode : byte_enum {
			// In this mode, the tag is being postprocessed for runtime values (automatically fill fields, etc)
			_tag_postprocess_mode_for_runtime = FALSE,
			// In this mode we're opening for tag editing (eg, tool process or guerilla) and should skip the postprocessing
			// code which prepares the tag for use in-game (Sapien and when building a cache)
			_tag_postprocess_mode_for_editor = TRUE,
		};
	};

	namespace Flags
	{
		enum {
			// Never streamed, unless the tag is loaded with _tag_load_for_editor_bit
			_tag_data_never_streamed_bit = 0,
			_tag_data_is_text_data_bit,
			// ie, 'debug data'
			_tag_data_not_streamed_to_cache_bit,

			// checked in the tag reference solving code.
			// last condition checked after an assortment of conditionals
			// and if this is TRUE, it won't resolve
			_tag_reference_unknown0_bit = 0,
			_tag_reference_non_resolving_bit,

			_tag_block_dont_read_children_bit =	0,

			// tag_instance of the tag group will have their file_checksum CRC'd into the resulting cache tag header's crc field 
			_tag_group_include_in_tags_checksum_bit = 0,
			// only seen preferences_network_game use this
			_tag_group_unknown1_bit,
			// haven't seen this used at all
			_tag_group_unknown2_bit,
			// majority of tags have this set
			_tag_group_reloadable_bit,

			// When this is set, implies _tag_postprocess_mode_for_editor, else _for_runtime
			_tag_load_for_editor_bit = 0,
			// Verify the tag file exists first
			// TODO: pretty sure this is 'is_new', so refactor to _tag_load_is_new_bit
			_tag_load_verify_exist_first_bit,
			// If set: child references of the tag being loaded are not loaded themselves
			// Else, child references are loaded from disk
			_tag_load_non_resolving_references_bit,
		};
	};


	struct tag_field
	{
		Enums::field_type type; PAD16;
		cstring name;
		void* definition;

		template<typename T> API_INLINE T* Definition() const { return CAST_PTR(T*, definition); }
	}; BOOST_STATIC_ASSERT( sizeof(tag_field) == 0xC );

	// Called as each element is read from the tag stream
	typedef bool (PLATFORM_API* proc_tag_block_postprocess_element)(void* element, Enums::tag_postprocess_mode mode);
	// if [formatted_buffer] returns empty, the default block formatting is done
	typedef cstring (PLATFORM_API* proc_tag_block_format)(datum_index tag_index, tag_block* block, int32 element_index, char formatted_buffer[Enums::k_tag_block_format_buffer_size]);
	typedef void (PLATFORM_API* proc_tag_block_dispose_element)(tag_block* block, int32 element_index);
	struct tag_block_definition
	{
		cstring name;
		long_flags flags;
		int32 maximum_element_count;
		size_t element_size;
		void* unused0;
		tag_field* fields;
		void* unused1;
		proc_tag_block_postprocess_element postprocess_proc;
		proc_tag_block_format format_proc;
		proc_tag_block_dispose_element dispose_element_proc;
		byte_swap_code_t* byte_swap_codes;

#if PLATFORM_IS_EDITOR
		// Searches the definition for a field of type [field_type] with a name which starts 
		// with [name] characters. Optionally starts at a specific field index.
		// Returns NONE if this fails.
		int32 find_field_index(_enum field_type, cstring name, int32 start_index = NONE) const;
#endif
	}; BOOST_STATIC_ASSERT( sizeof(tag_block_definition) == 0x2C );

	typedef void (PLATFORM_API* proc_tag_data_byte_swap)(void* block_element, void* address, int32 size);
	struct tag_data_definition
	{
		cstring name;
		long_flags flags;
		int32 maximum_size;
		proc_tag_data_byte_swap byte_swap_proc;
	}; BOOST_STATIC_ASSERT( sizeof(tag_data_definition) == 0x10 );

	struct tag_reference_definition
	{
		long_flags flags;
		tag group_tag;
		tag* group_tags;
	}; BOOST_STATIC_ASSERT( sizeof(tag_reference_definition) == 0xC );

	// Postprocess a tag definition (eg, automate the creation of fields, etc)
	// Called once the tag has been fully loaded (header_block_definition's postprocess is called before this)
	typedef bool (PLATFORM_API* proc_tag_group_postprocess)(datum_index tag_index, Enums::tag_postprocess_mode mode);
	struct tag_group
	{
		cstring name;
		long_flags flags;
		tag group_tag;
		tag parent_group_tag;
		int16 version; PAD16;
		proc_tag_group_postprocess postprocess_proc;
		tag_block_definition* header_block_definition;
		tag child_group_tags[Enums::k_maximum_children_per_tag];
		int16 child_count; PAD16;
	}; BOOST_STATIC_ASSERT( sizeof(tag_group) == 0x60 );


	struct s_tag_instance : Memory::s_datum_base_aligned
	{
		char filename[Enums::k_max_tag_name_length+1];			// 0x4
		tag group_tag;				// 0x104
		tag parent_group_tags[2];	// 0x108 0x10C
		bool is_verified;			// 0x110 was loaded with Flags::_tag_load_for_editor_bit
		bool is_read_only;			// 0x111
		bool is_orphan;				// 0x112
		bool is_reload;				// 0x113 true if this instance is the one used for another tag during tag_reload
		datum_index reload_index;	// 0x114 index of the instance used to reload -this- tag's definition
		uint32 file_checksum;		// 0x118
		tag_block root_block;		// 0x11C, 0x120, 0x124
	}; BOOST_STATIC_ASSERT( sizeof(s_tag_instance) == 0x128 );


	namespace TagGroups
	{
		struct s_tag_field_definition
		{
			size_t size;
		};

		struct s_tag_field_scan_state
		{
			const tag_field* fields;
			void* fields_address;
			long_flags field_types[BIT_VECTOR_SIZE_IN_DWORDS(Enums::k_number_of_tag_field_types)];
			int16 field_index;
			int16 field_size;
			int32 field_offset;
			bool done; PAD8;
			int16 stack_index;
			struct {
				int16 field_index;
				int16 count;
			}stack[Enums::k_tag_field_scan_stack_size];

			const tag_field* found_field;
			void* found_field_address;
		}; BOOST_STATIC_ASSERT( sizeof(s_tag_field_scan_state) == 0x64 );


		class c_tag_field_scanner
		{
			s_tag_field_scan_state m_state;

		public:
			inline bool IsDone() const					{ return m_state.done; }

			inline void* GetAddress() const				{ return m_state.fields_address; }

			inline int32 GetFieldIndex() const			{ return m_state.field_index; }
			inline size_t GetFieldSize() const			{ return CAST(size_t, m_state.field_size); }
			inline size_t GetFieldOffset() const		{ return CAST(size_t, m_state.field_offset); }

			inline Enums::field_type GetTagFieldType() const{ return m_state.found_field->type; }
			inline cstring GetTagFieldName() const			{ return m_state.found_field->name; }
			template<typename T>
			inline T* GetTagFieldDefinition() const			{ return m_state.found_field->Definition<T>(); }

			inline void* GetFieldAddress() const		{ return m_state.found_field_address; }
			template<typename T>
			inline T* GetFieldAs() const				{ return CAST_PTR(T*, m_state.found_field_address); }

		public:
			c_tag_field_scanner(const tag_field* fields, void* fields_address);

			c_tag_field_scanner& AddFieldType(Enums::field_type field_type);

			c_tag_field_scanner& AddAllFieldTypes();

			bool Scan();

			bool TagFieldIsStringId() const;


			// an interface to a found tag field and its definition
			struct s_iterator_result
			{
			private:
				const c_tag_field_scanner& m_scanner;

			public:
				s_iterator_result(const c_tag_field_scanner& scanner) : m_scanner(scanner) {}

				// Field's index, relative to the parent block's fields list
				inline int32 GetIndex() const			{ return m_scanner.GetFieldIndex(); }
				// Field's individual size
				inline size_t GetSize() const			{ return m_scanner.GetFieldSize(); }
				// Field's offset, relative to the parent block
				inline size_t GetOffset() const			{ return m_scanner.GetFieldOffset(); }

				// Field's type
				inline Enums::field_type GetType() const{ return m_scanner.GetTagFieldType(); }
				// Field's name
				inline cstring GetName() const			{ return m_scanner.GetTagFieldName(); }
				// Treat the field's definition as a T*
				template<typename T>
				inline T* DefinitionAs() const			{ return m_scanner.GetTagFieldDefinition<T>(); }

				// Instance's address
				inline void* GetAddress() const			{ return m_scanner.GetFieldAddress(); }
				// Treat the instance's address as a T*
				template<typename T>
				inline T* As() const					{ return m_scanner.GetFieldAs<T>(); }

				bool IsStringId() const					{ return m_scanner.TagFieldIsStringId(); }
			};

			struct s_iterator
			{
			private:
				c_tag_field_scanner* m_scanner;

				inline bool IsEndHack() const			{ return m_scanner == nullptr; }

			public:
				s_iterator(c_tag_field_scanner* scanner) : m_scanner(scanner) {}

				bool operator!=(const s_iterator& other) const;

				inline s_iterator& operator++()
				{
					m_scanner->Scan();
					return *this;
				}
				inline s_iterator_result operator*() const
				{
					return s_iterator_result(*m_scanner);
				}
			};

			inline s_iterator begin() /*const*/
			{
				auto iter = s_iterator(this);
				this->Scan();
				return iter;
			}
			inline static const s_iterator end() /*const*/
			{
				return s_iterator(nullptr);
			}
		};
	};
};