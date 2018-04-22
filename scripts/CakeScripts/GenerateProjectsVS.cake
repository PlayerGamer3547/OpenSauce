#reference "../../bin/BuildUtilities/Debug/BuildUtilities.dll"
#reference "../../bin/Cake.Gyp/Debug/Cake.Gyp.dll"
#load "Common/Common.cake"

using System.Xml.Linq;
using System.Xml.XPath;
using System.Xml;
using System.IO;
using BuildUtilities.VisualStudio;

Task("PullNuGetDependencies")
	.Does (() =>
	{

	});

Task("GenerateProjectTinyXml")
	.IsDependentOn("PullNuGetDependencies")
	.Does(()=>
	{
		Information("Building TinyXml project");
		var workingDirectory = GetRootedPath("build");
		GenerateProject(
			GetRootedPath("external/gyp"),
			"TinyXml.gyp",
			new GypSettings
			{
				WorkingDirectory = workingDirectory,
				OutputPlatform = GypOutputPlatform.VisualStudio2017,
				OutputDirectory = GetRootedPath("build/TinyXml"),
			}
		);
	});

Task("GenerateProjectGWEN")
	.IsDependentOn("PullNuGetDependencies")
	.Does(()=>
	{
		Information("Building GWEN project");
		var workingDirectory = GetRootedPath("build");
		GenerateProject(
			GetRootedPath("external/gyp"),
			"GWEN.gyp",
			new GypSettings
			{
				WorkingDirectory = workingDirectory,
				OutputPlatform = GypOutputPlatform.VisualStudio2017,
				OutputDirectory = GetRootedPath("build/GWEN"),
			}
		);
	});

Task("GenerateProjectMongoose")
	.IsDependentOn("PullNuGetDependencies")
	.Does(()=>
	{
		Information("Building Mongoose project");
		var workingDirectory = GetRootedPath("build");
		GenerateProject(
			GetRootedPath("external/gyp"),
			"Mongoose.gyp",
			new GypSettings
			{
				WorkingDirectory = workingDirectory,
				OutputPlatform = GypOutputPlatform.VisualStudio2017,
				OutputDirectory = GetRootedPath("build/Mongoose"),
			}
		);
	});

Task("GenerateProjectGameSpyOpen")
	.IsDependentOn("PullNuGetDependencies")
	.Does(()=>
	{
		Information("Building GameSpyOpen project");
		var workingDirectory = GetRootedPath("build");
		GenerateProject(
			GetRootedPath("external/gyp"),
			"GameSpyOpen.gyp",
			new GypSettings
			{
				WorkingDirectory = workingDirectory,
				OutputPlatform = GypOutputPlatform.VisualStudio2017,
				OutputDirectory = GetRootedPath("build/GameSpyOpen"),
			}
		);
	});

Task("GenerateProject7zip")
	.IsDependentOn("PullNuGetDependencies")
	.Does(()=>
	{
		Information("Building 7zip project");
		var workingDirectory = GetRootedPath("build");
		GenerateProject(
			GetRootedPath("external/gyp"),
			"7zip.gyp",
			new GypSettings
			{
				WorkingDirectory = workingDirectory,
				OutputPlatform = GypOutputPlatform.VisualStudio2017,
				OutputDirectory = GetRootedPath("build/7zip"),
			}
		);
	});

Task("GenerateProjectZlib")
	.IsDependentOn("PullNuGetDependencies")
	.Does(()=>
	{
		Information("Building Zlib project");
		var workingDirectory = GetRootedPath("build");
		GenerateProject(
			GetRootedPath("external/gyp"),
			"Zlib.gyp",
			new GypSettings
			{
				WorkingDirectory = workingDirectory,
				OutputPlatform = GypOutputPlatform.VisualStudio2017,
				OutputDirectory = GetRootedPath("build/Zlib"),
			}
		);
	});

Task("GenerateProjectOpenSauce")
	.IsDependentOn("PullNuGetDependencies")
	.Does(()=>
	{
		Information("Building OpenSauce project");
		var workingDirectory = GetRootedPath("build");
		GenerateProject(
			GetRootedPath("external/gyp"),
			"OpenSauce.gyp",
			new GypSettings
			{
				WorkingDirectory = workingDirectory,
				OutputPlatform = GypOutputPlatform.VisualStudio2017,
				OutputDirectory = GetRootedPath("build/msvs2017_generated"),
			}
		);
	});


Task("CleanupProjects")
	.IsDependentOn("GenerateProjectTinyXml")
	.IsDependentOn("GenerateProjectGWEN")
	.IsDependentOn("GenerateProjectMongoose")
	.IsDependentOn("GenerateProjectGameSpyOpen")
	.IsDependentOn("GenerateProject7zip")
	.IsDependentOn("GenerateProjectZlib")
	.IsDependentOn("GenerateProjectOpenSauce")
	.Does(()=>
	{
		ProjectUtilities.SetRunCodeAnalysis(GetRootedPath("build/msvs2017_generated/blam.vcxproj"));
		ProjectUtilities.TrimPathFromFilters(GetRootedPath("build/msvs2017_generated/blam.vcxproj.filters"), "../source/blam");
		ProjectUtilities.SetRunCodeAnalysis(GetRootedPath("build/msvs2017_generated/yelo.vcxproj"));
		ProjectUtilities.TrimPathFromFilters(GetRootedPath("build/msvs2017_generated/yelo.vcxproj.filters"), "../source/yelo");
		ProjectUtilities.SetRunCodeAnalysis(GetRootedPath("build/msvs2017_generated/halo.vcxproj"));
		ProjectUtilities.TrimPathFromFilters(GetRootedPath("build/msvs2017_generated/halo.vcxproj.filters"), "../source/halo");

		ProjectUtilities.TrimPathFromFilters(GetRootedPath("build/7zip/7zip.vcxproj.filters"), "../external/7zip");
		ProjectUtilities.TrimPathFromFilters(GetRootedPath("build/TinyXml/TinyXml.vcxproj.filters"), "../external/TinyXml");
		ProjectUtilities.TrimPathFromFilters(GetRootedPath("build/GameSpyOpen/GameSpyOpen.vcxproj.filters"), "../external/GameSpyOpen");
		ProjectUtilities.TrimPathFromFilters(GetRootedPath("build/GWEN/GWEN.vcxproj.filters"), "../external/GWEN");
		ProjectUtilities.TrimPathFromFilters(GetRootedPath("build/Mongoose/Mongoose.vcxproj.filters"), "../external/Mongoose");
		ProjectUtilities.TrimPathFromFilters(GetRootedPath("build/Zlib/Zlib.vcxproj.filters"), "../external/Zlib");
	});

Task("GenerateProjectsVS")
	.IsDependentOn("CleanupProjects");

RunTarget("GenerateProjectsVS");