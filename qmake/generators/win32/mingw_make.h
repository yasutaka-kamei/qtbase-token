begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the qmake application of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|MINGW_MAKE_H
end_ifndef
begin_define
DECL|macro|MINGW_MAKE_H
define|#
directive|define
name|MINGW_MAKE_H
end_define
begin_include
include|#
directive|include
file|"winmakefile.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|MingwMakefileGenerator
range|:
name|public
name|Win32MakefileGenerator
block|{
name|public
operator|:
name|MingwMakefileGenerator
argument_list|()
block|;
operator|~
name|MingwMakefileGenerator
argument_list|()
block|;
name|protected
operator|:
name|QString
name|escapeDependencyPath
argument_list|(
argument|const QString&path
argument_list|)
specifier|const
block|;
name|ProString
name|escapeDependencyPath
argument_list|(
argument|const ProString&path
argument_list|)
specifier|const
block|{
return|return
name|MakefileGenerator
operator|::
name|escapeDependencyPath
argument_list|(
name|path
argument_list|)
return|;
block|}
name|virtual
name|ProString
name|fixLibFlag
argument_list|(
specifier|const
name|ProString
operator|&
name|lib
argument_list|)
block|;
name|QString
name|getLibTarget
argument_list|()
block|;
name|virtual
name|QString
name|getManifestFileForRcFile
argument_list|()
specifier|const
block|;
name|bool
name|writeMakefile
argument_list|(
name|QTextStream
operator|&
argument_list|)
block|;
name|void
name|init
argument_list|()
block|;
name|private
operator|:
name|void
name|writeMingwParts
argument_list|(
name|QTextStream
operator|&
argument_list|)
block|;
name|void
name|writeIncPart
argument_list|(
name|QTextStream
operator|&
name|t
argument_list|)
block|;
name|void
name|writeLibsPart
argument_list|(
name|QTextStream
operator|&
name|t
argument_list|)
block|;
name|void
name|writeObjectsPart
argument_list|(
name|QTextStream
operator|&
name|t
argument_list|)
block|;
name|void
name|writeBuildRulesPart
argument_list|(
name|QTextStream
operator|&
name|t
argument_list|)
block|;
name|void
name|writeRcFilePart
argument_list|(
name|QTextStream
operator|&
name|t
argument_list|)
block|;
name|QStringList
operator|&
name|findDependencies
argument_list|(
specifier|const
name|QString
operator|&
name|file
argument_list|)
block|;
name|QString
name|preCompHeaderOut
block|;
name|virtual
name|bool
name|findLibraries
argument_list|()
block|;
name|QString
name|objectsLinkLine
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|function|~MingwMakefileGenerator
specifier|inline
name|MingwMakefileGenerator
operator|::
operator|~
name|MingwMakefileGenerator
argument_list|()
block|{ }
name|QT_END_NAMESPACE
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// MINGW_MAKE_H
end_comment
end_unit
