/*
	BlamLib: .NET SDK for the Blam Engine

	See license\BlamLib\BlamLib for specific license information
*/
﻿
namespace BlamLib
{
	partial class Program
	{
#if !NO_HALO3
		/// <summary>
		/// Halo 3 global wide settings
		/// </summary>
		public static class Halo3
		{
			#region Manager
			static Blam.Halo3.GameDefinition manager = new Blam.Halo3.GameDefinition();
			/// <summary>
			/// Halo 3's specific manager instance
			/// </summary>
			public static Blam.Halo3.GameDefinition Manager { get { return manager; } }
			#endregion

			/// <summary>
			/// Initialize the resources used by the Halo 3 systems
			/// </summary>
			public static void Initialize()
			{
				manager.Read(Managers.GameManager.GetRelativePath(BlamLib.Managers.GameManager.Namespace.Halo3), "Halo3.xml");
			}

			/// <summary>
			/// Close the resources used by the Halo 3 systems
			/// </summary>
			public static void Close()
			{
				CloseBeta();
				CloseEpsilon();
				CloseXbox();
				manager.Close();
			}

			#region Beta
			/// <summary>
			/// Path to the file 'mainmenu.map'
			/// </summary>
			static string BetaMainmenuPath = string.Empty;

			public static BlamLib.Blam.Halo3.CacheFile BetaMainmenu;

			/// <summary>
			/// Path to the file 'shared.map'
			/// </summary>
			static string BetaSharedPath = string.Empty;

			public static BlamLib.Blam.Halo3.CacheFile BetaShared;

			/// <summary>
			/// Loads the Halo 3 files needed to fully run this library
			/// </summary>
			/// <remarks>
			/// Path[0] = Mainmenu
			/// Path[1] = Shared
			/// </remarks>
			/// <param name="paths"></param>
			public static void LoadBeta(params string[] paths)
			{
				Blam.DatumIndex di;

				if (paths.Length >= 1 && System.IO.File.Exists(paths[0]))
				{
					di = manager.OpenResourceCacheFile(BlamVersion.Halo3_Beta, BetaMainmenuPath = paths[0]);
					BetaMainmenu = manager.GetCacheFile(di) as BlamLib.Blam.Halo3.CacheFile;
					BetaMainmenu.EngineVersion = BlamVersion.Halo3_Beta;
					BetaMainmenu.ReadResourceCache();
				}

				if (paths.Length >= 2 && System.IO.File.Exists(paths[1]))
				{
					di = manager.OpenResourceCacheFile(BlamVersion.Halo3_Beta, BetaSharedPath = paths[1]);
					BetaShared = manager.GetCacheFile(di) as BlamLib.Blam.Halo3.CacheFile;
					BetaShared.EngineVersion = BlamVersion.Halo3_Beta;
					BetaShared.ReadResourceCache();
				}
			}

			private static void CloseBeta()
			{
				if (BetaMainmenu != null)	manager.CloseCacheFile(BetaMainmenu.CacheId);
				if (BetaShared != null)		manager.CloseCacheFile(BetaShared.CacheId);
			}
			#endregion

			#region Epsilon
			/// <summary>
			/// Path to the file 'mainmenu.map'
			/// </summary>
			static string EpsilonMainmenuPath = string.Empty;

			public static BlamLib.Blam.Halo3.CacheFile EpsilonMainmenu;

			/// <summary>
			/// Path to the file 'shared.map'
			/// </summary>
			static string EpsilonSharedPath = string.Empty;

			public static BlamLib.Blam.Halo3.CacheFile EpsilonShared;

			/// <summary>
			/// Path to the file 'campaign.map'
			/// </summary>
			static string EpsilonCampaignPath = string.Empty;

			public static BlamLib.Blam.Halo3.CacheFile EpsilonCampaign;

			/// <summary>
			/// Loads the Halo 3 files needed to fully run this library
			/// </summary>
			/// <remarks>
			/// Path[0] = Mainmenu
			/// Path[1] = Shared
			/// </remarks>
			/// <param name="paths"></param>
			public static void LoadEpsilon(params string[] paths)
			{
				Blam.DatumIndex di;

				if (paths.Length >= 1 && System.IO.File.Exists(paths[0]))
				{
					di = manager.OpenResourceCacheFile(BlamVersion.Halo3_Epsilon, EpsilonMainmenuPath = paths[0]);
					EpsilonMainmenu = manager.GetCacheFile(di) as BlamLib.Blam.Halo3.CacheFile;
					EpsilonMainmenu.ReadResourceCache();
				}

				if (paths.Length >= 2 && System.IO.File.Exists(paths[1]))
				{
					di = manager.OpenResourceCacheFile(BlamVersion.Halo3_Epsilon, EpsilonSharedPath = paths[1]);
					EpsilonShared = manager.GetCacheFile(di) as BlamLib.Blam.Halo3.CacheFile;
					EpsilonShared.ReadResourceCache();
				}

				if (paths.Length >= 3 && System.IO.File.Exists(paths[2]))
				{
					di = manager.OpenResourceCacheFile(BlamVersion.Halo3_Epsilon, EpsilonCampaignPath = paths[2]);
					EpsilonCampaign = manager.GetCacheFile(di) as BlamLib.Blam.Halo3.CacheFile;
					EpsilonCampaign.ReadResourceCache();
				}
			}

			private static void CloseEpsilon()
			{
				if (EpsilonMainmenu != null)	manager.CloseCacheFile(EpsilonMainmenu.CacheId);
				if (EpsilonShared != null)		manager.CloseCacheFile(EpsilonShared.CacheId);
				if (EpsilonCampaign != null)	manager.CloseCacheFile(EpsilonCampaign.CacheId);
			}
			#endregion

			#region Xbox
			/// <summary>
			/// Path to the file 'mainmenu.map'
			/// </summary>
			static string XboxMainmenuPath = string.Empty;

			public static BlamLib.Blam.Halo3.CacheFile XboxMainmenu;

			/// <summary>
			/// Path to the file 'shared.map'
			/// </summary>
			static string XboxSharedPath = string.Empty;

			public static BlamLib.Blam.Halo3.CacheFile XboxShared;

			/// <summary>
			/// Path to the file 'campaign.map'
			/// </summary>
			static string XboxCampaignPath = string.Empty;

			public static BlamLib.Blam.Halo3.CacheFile XboxCampaign;

			/// <summary>
			/// Loads the Halo 3 files needed to fully run this library
			/// </summary>
			/// <remarks>
			/// Path[0] = Mainmenu
			/// Path[1] = Shared
			/// Path[2] = Single Player Shared
			/// </remarks>
			/// <param name="paths"></param>
			public static void LoadXbox(params string[] paths)
			{
				Blam.DatumIndex di;

				if (paths.Length >= 1 && System.IO.File.Exists(paths[0]))
				{
					di = manager.OpenResourceCacheFile(BlamVersion.Halo3_Xbox, XboxMainmenuPath = paths[0]);
					XboxMainmenu = manager.GetCacheFile(di) as BlamLib.Blam.Halo3.CacheFile;
					XboxMainmenu.ReadResourceCache();
				}

				if (paths.Length >= 2 && System.IO.File.Exists(paths[1]))
				{
					di = manager.OpenResourceCacheFile(BlamVersion.Halo3_Xbox, XboxSharedPath = paths[1]);
					XboxShared = manager.GetCacheFile(di) as BlamLib.Blam.Halo3.CacheFile;
					XboxShared.ReadResourceCache();
				}

				if (paths.Length >= 3 && System.IO.File.Exists(paths[2]))
				{
					di = manager.OpenResourceCacheFile(BlamVersion.Halo3_Xbox, XboxCampaignPath = paths[2]);
					XboxCampaign = manager.GetCacheFile(di) as BlamLib.Blam.Halo3.CacheFile;
					XboxCampaign.ReadResourceCache();
				}
			}

			private static void CloseXbox()
			{
				if (XboxMainmenu != null)	manager.CloseCacheFile(XboxMainmenu.CacheId);
				if (XboxShared != null)		manager.CloseCacheFile(XboxShared.CacheId);
				if (XboxCampaign != null)	manager.CloseCacheFile(XboxCampaign.CacheId);
			}
			#endregion

			/// <summary>
			/// Returns a CacheFile object based on a cache name
			/// </summary>
			/// <param name="ver">Halo3 engine version</param>
			/// <param name="cache_name">Blam based cache name</param>
			/// <returns>The CacheFile associated with <paramref name="cache_name"/></returns>
			public static Blam.Halo3.CacheFile FromLocation(BlamVersion ver, string cache_name)
			{
				if (string.IsNullOrEmpty(cache_name)) return null;

				Blam.CacheType t = BlamLib.Blam.CacheType.None;
				if (cache_name.Contains("mainmenu"))		t = BlamLib.Blam.CacheType.MainMenu;
				else if (cache_name.Contains("shared"))		t = BlamLib.Blam.CacheType.Shared;
				else if (cache_name.Contains("campaign"))	t = BlamLib.Blam.CacheType.SharedCampaign;
				else										throw new Debug.Exceptions.UnreachableException(cache_name);

				if (ver == BlamVersion.Halo3_Xbox)
				{
					switch (t)
					{
						case BlamLib.Blam.CacheType.MainMenu:		return XboxMainmenu;
						case BlamLib.Blam.CacheType.Shared:			return XboxShared;
						case BlamLib.Blam.CacheType.SharedCampaign:	return XboxCampaign;
					}
				}
				else if (ver == BlamVersion.Halo3_Epsilon)
				{
					switch (t)
					{
						case BlamLib.Blam.CacheType.MainMenu:		return EpsilonMainmenu;
						case BlamLib.Blam.CacheType.Shared:			return EpsilonShared;
						case BlamLib.Blam.CacheType.SharedCampaign:	return EpsilonCampaign;
					}
				}
				else if (ver == BlamVersion.Halo3_Beta)
				{
					switch (t)
					{
						case BlamLib.Blam.CacheType.MainMenu:		return BetaMainmenu;
						case BlamLib.Blam.CacheType.Shared:			return BetaShared;
						case BlamLib.Blam.CacheType.SharedCampaign:	throw new Debug.Exceptions.UnreachableException();
					}
				}

				return null;
			}

			/// <summary>
			/// Returns a CacheFile object based on a cache name
			/// </summary>
			/// <remarks>
			/// If the <paramref name="cache_name"/> is null or empty then <paramref name="is_internal"/> 
			/// gets set to true and null is returned. If null and <paramref name="is_internal"/> is not set, 
			/// the CacheFile is either not loaded or the location was invalid.
			/// </remarks>
			/// <param name="ver">Halo3 engine version</param>
			/// <param name="cache_name">Blam based cache name</param>
			/// <param name="is_internal">bool reference to set if the reference is internal</param>
			/// <returns>The CacheFile associated with <paramref name="cache_name"/></returns>
			public static Blam.Halo3.CacheFile FromLocation(BlamVersion ver, string cache_name, out bool is_internal)
			{
				is_internal = false;

				Blam.Halo3.CacheFile c = FromLocation(ver, cache_name);

				is_internal = c == null;
				return c;
			}
		};
#endif
	};
}