/*
	BlamLib: .NET SDK for the Blam Engine

	See license\BlamLib\BlamLib for specific license information
*/
﻿using System;
using System.Collections.Generic;

namespace BlamLib
{
	internal static partial class Tool
	{
		/// <summary>If <paramref name="ex"/> is not null, prints exception details to the Console</summary>
		/// <param name="mod_name"></param>
		/// <param name="ex"></param>
		static void DumpModificationException(string mod_name, Exception ex)
		{
			if (ex != null)
			{
				Console.WriteLine("error: an exception occurred when attempting to apply the {0} modifications", mod_name);
				Console.WriteLine();
				Console.WriteLine("exception details:");
				if (ex.Message != null) Console.WriteLine(ex.Message);
				Console.WriteLine(ex.StackTrace);
				Console.WriteLine();
			}
		}

		static void DumpArguments(int start_index, params string[] args)
		{
			Console.WriteLine("Argument dump follows:");
			if (start_index >= args.Length)
				Console.WriteLine("\tcan't dump an OOB index");
			else
			{
				for (int x = start_index; x < args.Length; x++)
					Console.WriteLine("\t\"{0}\"", args[x]);
				Console.WriteLine();
			}
		}
		public delegate void CommandFunction(params string[] args);

		public static Dictionary<string, CommandFunction> kCommands = new Dictionary<string, CommandFunction>()
		{
			{"build-tag-database", BuildTagDatabase},
			{"pack-cache-file", PackCache},
			{"apply-cheape", UnlockBlamTools},		//apply-cheape version g_path t_path s_path output
			{"apply-opensauce", UnlockBlamGames},	//apply-opensauce version c_path d_path output
			{"apply-opensauce-xna", PatchXna},		//apply-opensauce-xna output-path [hint-path]
		};

		public static bool RunCommand(string command, params string[] args)
		{
			BlamLib.Tool.CommandFunction func;
			if (kCommands.TryGetValue(command, out func))
			{
				func(args);
				return true;
			}

			return false;
		}

		public static void PrintUsage(string invalid_command)
		{
			if (invalid_command != null)
			{
				Console.WriteLine("This is not a command: {0}", invalid_command);
				Console.WriteLine("Use one of these commands:");
				foreach (var name in kCommands.Keys)
					Console.WriteLine(name);
			}
		}

		static void BuildTagDatabase(params string[] args)
		{
			if (args.Length < 2)
			{
				Console.WriteLine("");
				return;
			}

			string arg_source_tag = args[0];
			string arg_dest_db = args[1];
		}
	};
}