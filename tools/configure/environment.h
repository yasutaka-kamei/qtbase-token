begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qstring.h>
end_include
begin_include
include|#
directive|include
file|<qt_windows.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|enum|Compiler
name|enum
name|Compiler
block|{
DECL|enumerator|CC_UNKNOWN
name|CC_UNKNOWN
operator|=
literal|0
operator|,
DECL|enumerator|CC_BORLAND
name|CC_BORLAND
operator|=
literal|0x01
operator|,
DECL|enumerator|CC_MINGW
name|CC_MINGW
operator|=
literal|0x02
operator|,
DECL|enumerator|CC_INTEL
name|CC_INTEL
operator|=
literal|0x03
operator|,
DECL|enumerator|CC_NET2003
name|CC_NET2003
operator|=
literal|0x71
operator|,
DECL|enumerator|CC_NET2005
name|CC_NET2005
operator|=
literal|0x80
operator|,
DECL|enumerator|CC_NET2008
name|CC_NET2008
operator|=
literal|0x90
operator|,
DECL|enumerator|CC_NET2010
name|CC_NET2010
operator|=
literal|0x91
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_struct_decl
struct_decl|struct
name|CompilerInfo
struct_decl|;
end_struct_decl
begin_decl_stmt
name|class
name|Environment
block|{
name|public
label|:
specifier|static
name|Compiler
name|detectCompiler
parameter_list|()
function_decl|;
specifier|static
name|QString
name|detectQMakeSpec
parameter_list|()
function_decl|;
specifier|static
name|bool
name|detectExecutable
parameter_list|(
specifier|const
name|QString
modifier|&
name|executable
parameter_list|)
function_decl|;
specifier|static
name|int
name|execute
parameter_list|(
name|QStringList
name|arguments
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|additionalEnv
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|removeEnv
parameter_list|)
function_decl|;
specifier|static
name|bool
name|cpdir
parameter_list|(
specifier|const
name|QString
modifier|&
name|srcDir
parameter_list|,
specifier|const
name|QString
modifier|&
name|destDir
parameter_list|,
specifier|const
name|QString
modifier|&
name|includeSrcDir
init|=
name|QString
argument_list|()
parameter_list|)
function_decl|;
specifier|static
name|bool
name|rmdir
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
name|private
label|:
specifier|static
name|Compiler
name|detectedCompiler
decl_stmt|;
specifier|static
name|CompilerInfo
modifier|*
name|compilerInfo
parameter_list|(
name|Compiler
name|compiler
parameter_list|)
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
