begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the qmake application of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|MSVC_VCPROJ_H
end_ifndef
begin_define
DECL|macro|MSVC_VCPROJ_H
define|#
directive|define
name|MSVC_VCPROJ_H
end_define
begin_include
include|#
directive|include
file|"winmakefile.h"
end_include
begin_include
include|#
directive|include
file|"msvc_objectmodel.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|enum|Target
name|enum
name|Target
block|{
DECL|enumerator|Application
name|Application
operator|,
DECL|enumerator|SharedLib
name|SharedLib
operator|,
DECL|enumerator|StaticLib
name|StaticLib
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
DECL|variable|QUuid
name|class
name|QUuid
decl_stmt|;
end_decl_stmt
begin_struct_decl
struct_decl|struct
name|VcsolutionDepend
struct_decl|;
end_struct_decl
begin_decl_stmt
name|class
name|VcprojGenerator
range|:
name|public
name|Win32MakefileGenerator
block|{
name|bool
name|init_flag
block|;
name|bool
name|is64Bit
block|;
name|bool
name|writeVcprojParts
argument_list|(
name|QTextStream
operator|&
argument_list|)
block|;
name|bool
name|writeMakefile
argument_list|(
name|QTextStream
operator|&
argument_list|)
block|;
name|bool
name|writeProjectMakefile
argument_list|()
block|;
name|void
name|init
argument_list|()
block|;
name|public
operator|:
name|VcprojGenerator
argument_list|()
block|;
operator|~
name|VcprojGenerator
argument_list|()
block|;
name|QString
name|defaultMakefile
argument_list|()
specifier|const
block|;
name|QString
name|precompH
block|,
name|precompHFilename
block|,
name|precompCPP
block|,
name|precompObj
block|,
name|precompPch
block|;
name|bool
name|autogenPrecompCPP
block|;
specifier|static
name|bool
name|hasBuiltinCompiler
argument_list|(
specifier|const
name|QString
operator|&
name|file
argument_list|)
block|;
name|QHash
operator|<
name|QString
block|,
name|QStringList
operator|>
name|extraCompilerSources
block|;
name|QHash
operator|<
name|QString
block|,
name|QStringList
operator|>
name|extraCompilerOutputs
block|;
name|bool
name|usePCH
block|;
name|VCProjectWriter
operator|*
name|projectWriter
block|;
name|protected
operator|:
name|virtual
name|VCProjectWriter
operator|*
name|createProjectWriter
argument_list|()
block|;
name|virtual
name|bool
name|doDepends
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|//never necesary
name|virtual
name|void
name|processSources
argument_list|()
block|{
name|filterIncludedFiles
argument_list|(
literal|"SOURCES"
argument_list|)
block|;
name|filterIncludedFiles
argument_list|(
literal|"GENERATED_SOURCES"
argument_list|)
block|; }
name|virtual
name|QString
name|replaceExtraCompilerVariables
argument_list|(
specifier|const
name|QString
operator|&
argument_list|,
specifier|const
name|QStringList
operator|&
argument_list|,
specifier|const
name|QStringList
operator|&
argument_list|)
block|;
specifier|inline
name|QString
name|replaceExtraCompilerVariables
argument_list|(
argument|const QString&val
argument_list|,
argument|const QString&in
argument_list|,
argument|const QString&out
argument_list|)
block|{
return|return
name|MakefileGenerator
operator|::
name|replaceExtraCompilerVariables
argument_list|(
name|val
argument_list|,
name|in
argument_list|,
name|out
argument_list|)
return|;
block|}
name|virtual
name|bool
name|supportsMetaBuild
argument_list|()
block|{
return|return
name|true
return|;
block|}
name|virtual
name|bool
name|supportsMergedBuilds
argument_list|()
block|{
return|return
name|true
return|;
block|}
name|virtual
name|bool
name|mergeBuildProject
argument_list|(
name|MakefileGenerator
operator|*
name|other
argument_list|)
block|;
name|virtual
name|bool
name|openOutput
argument_list|(
argument|QFile&file
argument_list|,
argument|const QString&build
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|outputVariables
argument_list|()
block|;
name|QString
name|fixFilename
argument_list|(
argument|QString ofile
argument_list|)
specifier|const
block|;
name|void
name|initOld
argument_list|()
block|;
name|virtual
name|void
name|initProject
argument_list|()
block|;
name|void
name|initConfiguration
argument_list|()
block|;
name|void
name|initCompilerTool
argument_list|()
block|;
name|void
name|initLinkerTool
argument_list|()
block|;
name|void
name|initLibrarianTool
argument_list|()
block|;
name|void
name|initManifestTool
argument_list|()
block|;
name|void
name|initResourceTool
argument_list|()
block|;
name|void
name|initIDLTool
argument_list|()
block|;
name|void
name|initCustomBuildTool
argument_list|()
block|;
name|void
name|initPreBuildEventTools
argument_list|()
block|;
name|void
name|initPostBuildEventTools
argument_list|()
block|;
name|void
name|initDeploymentTool
argument_list|()
block|;
name|void
name|initPreLinkEventTools
argument_list|()
block|;
name|void
name|initRootFiles
argument_list|()
block|;
name|void
name|initSourceFiles
argument_list|()
block|;
name|void
name|initHeaderFiles
argument_list|()
block|;
name|void
name|initGeneratedFiles
argument_list|()
block|;
name|void
name|initTranslationFiles
argument_list|()
block|;
name|void
name|initFormFiles
argument_list|()
block|;
name|void
name|initResourceFiles
argument_list|()
block|;
name|void
name|initDeploymentFiles
argument_list|()
block|;
name|void
name|initLexYaccFiles
argument_list|()
block|;
name|void
name|initExtraCompilerOutputs
argument_list|()
block|;
name|void
name|writeSubDirs
argument_list|(
name|QTextStream
operator|&
name|t
argument_list|)
block|;
comment|// Called from VCXProj backend
name|QUuid
name|getProjectUUID
argument_list|(
specifier|const
name|QString
operator|&
name|filename
operator|=
name|QString
argument_list|()
argument_list|)
block|;
comment|// Called from VCXProj backend
name|Target
name|projectTarget
block|;
comment|// Used for single project
name|VCProjectSingleConfig
name|vcProject
block|;
comment|// Holds all configurations for glue (merged) project
name|QList
operator|<
name|VcprojGenerator
operator|*
operator|>
name|mergedProjects
block|;
name|private
operator|:
name|ProStringList
name|collectDependencies
argument_list|(
name|QMakeProject
operator|*
name|proj
argument_list|,
name|QHash
operator|<
name|QString
argument_list|,
name|QString
operator|>
operator|&
name|projLookup
argument_list|,
name|QHash
operator|<
name|QString
argument_list|,
name|QString
operator|>
operator|&
name|projGuids
argument_list|,
name|QHash
operator|<
name|VcsolutionDepend
operator|*
argument_list|,
name|QStringList
operator|>
operator|&
name|extraSubdirs
argument_list|,
name|QHash
operator|<
name|QString
argument_list|,
name|VcsolutionDepend
operator|*
operator|>
operator|&
name|solution_depends
argument_list|,
name|QList
operator|<
name|VcsolutionDepend
operator|*
operator|>
operator|&
name|solution_cleanup
argument_list|,
name|QTextStream
operator|&
name|t
argument_list|,
name|QHash
operator|<
name|QString
argument_list|,
name|ProStringList
operator|>
operator|&
name|subdirProjectLookup
argument_list|,
specifier|const
name|ProStringList
operator|&
name|allDependencies
operator|=
name|ProStringList
argument_list|()
argument_list|)
block|;
name|QUuid
name|increaseUUID
argument_list|(
specifier|const
name|QUuid
operator|&
name|id
argument_list|)
block|;
name|friend
name|class
name|VCFilter
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|function|defaultMakefile
specifier|inline
name|QString
name|VcprojGenerator
operator|::
name|defaultMakefile
argument_list|()
specifier|const
block|{
return|return
name|project
operator|->
name|first
argument_list|(
literal|"TARGET"
argument_list|)
operator|+
name|project
operator|->
name|first
argument_list|(
literal|"VCPROJ_EXTENSION"
argument_list|)
return|;
block|}
end_expr_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// MSVC_VCPROJ_H
end_comment
end_unit
