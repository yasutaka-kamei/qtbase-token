begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2013 Klaralvdalens Datakonsult AB (KDAB) ** Contact: http://www.qt-project.org/legal ** ** This file is part of the utilities of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|SPECPARSER_H
end_ifndef
begin_define
DECL|macro|SPECPARSER_H
define|#
directive|define
name|SPECPARSER_H
end_define
begin_include
include|#
directive|include
file|<QStringList>
end_include
begin_include
include|#
directive|include
file|<QVariant>
end_include
begin_decl_stmt
DECL|variable|QTextStream
name|class
name|QTextStream
decl_stmt|;
end_decl_stmt
begin_struct
DECL|struct|Version
struct|struct
name|Version
block|{
DECL|member|major
name|int
name|major
decl_stmt|;
DECL|member|minor
name|int
name|minor
decl_stmt|;
block|}
struct|;
end_struct
begin_expr_stmt
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|Version
operator|&
name|lhs
operator|,
specifier|const
name|Version
operator|&
name|rhs
operator|)
block|{
return|return
operator|(
name|lhs
operator|.
name|major
operator|==
name|rhs
operator|.
name|major
operator|&&
name|lhs
operator|.
name|minor
operator|==
name|rhs
operator|.
name|minor
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|Version
operator|&
name|lhs
operator|,
specifier|const
name|Version
operator|&
name|rhs
operator|)
block|{
if|if
condition|(
name|lhs
operator|.
name|major
operator|!=
name|rhs
operator|.
name|major
condition|)
return|return
operator|(
name|lhs
operator|.
name|major
operator|<
name|rhs
operator|.
name|major
operator|)
return|;
else|else
return|return
operator|(
name|lhs
operator|.
name|minor
operator|<
name|rhs
operator|.
name|minor
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|>
operator|(
specifier|const
name|Version
operator|&
name|lhs
operator|,
specifier|const
name|Version
operator|&
name|rhs
operator|)
block|{
if|if
condition|(
name|lhs
operator|.
name|major
operator|!=
name|rhs
operator|.
name|major
condition|)
return|return
operator|(
name|lhs
operator|.
name|major
operator|>
name|rhs
operator|.
name|major
operator|)
return|;
else|else
return|return
operator|(
name|lhs
operator|.
name|minor
operator|>
name|rhs
operator|.
name|minor
operator|)
return|;
block|}
end_expr_stmt
begin_function
DECL|function|qHash
specifier|inline
name|uint
name|qHash
parameter_list|(
specifier|const
name|Version
modifier|&
name|v
parameter_list|)
block|{
return|return
name|qHash
argument_list|(
name|v
operator|.
name|major
operator|*
literal|100
operator|+
name|v
operator|.
name|minor
operator|*
literal|10
argument_list|)
return|;
block|}
end_function
begin_struct
DECL|struct|VersionProfile
struct|struct
name|VersionProfile
block|{
DECL|enum|OpenGLProfile
enum|enum
name|OpenGLProfile
block|{
DECL|enumerator|CoreProfile
name|CoreProfile
init|=
literal|0
block|,
DECL|enumerator|CompatibilityProfile
name|CompatibilityProfile
block|}
enum|;
DECL|function|hasProfiles
specifier|inline
name|bool
name|hasProfiles
argument_list|()
specifier|const
block|{
return|return
operator|(
name|version
operator|.
name|major
operator|>
literal|3
operator|||
operator|(
name|version
operator|.
name|major
operator|==
literal|3
operator|&&
name|version
operator|.
name|minor
operator|>
literal|1
operator|)
operator|)
return|;
block|}
DECL|member|version
name|Version
name|version
decl_stmt|;
DECL|member|profile
name|OpenGLProfile
name|profile
decl_stmt|;
block|}
struct|;
end_struct
begin_expr_stmt
DECL|function|operator
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|VersionProfile
operator|&
name|lhs
operator|,
specifier|const
name|VersionProfile
operator|&
name|rhs
operator|)
block|{
if|if
condition|(
name|lhs
operator|.
name|profile
operator|!=
name|rhs
operator|.
name|profile
condition|)
return|return
name|false
return|;
end_expr_stmt
begin_return
return|return
name|lhs
operator|.
name|version
operator|==
name|rhs
operator|.
name|version
return|;
end_return
begin_expr_stmt
unit|}  inline
DECL|function|operator
name|bool
name|operator
operator|<
operator|(
specifier|const
name|VersionProfile
operator|&
name|lhs
operator|,
specifier|const
name|VersionProfile
operator|&
name|rhs
operator|)
block|{
if|if
condition|(
name|lhs
operator|.
name|profile
operator|!=
name|rhs
operator|.
name|profile
condition|)
return|return
operator|(
name|lhs
operator|.
name|profile
operator|<
name|rhs
operator|.
name|profile
operator|)
return|;
end_expr_stmt
begin_return
return|return
operator|(
name|lhs
operator|.
name|version
operator|<
name|rhs
operator|.
name|version
operator|)
return|;
end_return
begin_function
unit|}  inline
DECL|function|qHash
name|uint
name|qHash
parameter_list|(
specifier|const
name|VersionProfile
modifier|&
name|v
parameter_list|)
block|{
return|return
name|qHash
argument_list|(
name|static_cast
operator|<
name|int
operator|>
operator|(
name|v
operator|.
name|profile
operator|*
literal|1000
operator|)
operator|+
name|v
operator|.
name|version
operator|.
name|major
operator|*
literal|100
operator|+
name|v
operator|.
name|version
operator|.
name|minor
operator|*
literal|10
argument_list|)
return|;
block|}
end_function
begin_struct
DECL|struct|Argument
struct|struct
name|Argument
block|{
DECL|enum|Direction
enum|enum
name|Direction
block|{
DECL|enumerator|In
name|In
init|=
literal|0
block|,
DECL|enumerator|Out
name|Out
block|}
enum|;
DECL|enum|Mode
enum|enum
name|Mode
block|{
DECL|enumerator|Value
name|Value
init|=
literal|0
block|,
DECL|enumerator|Array
name|Array
block|,
DECL|enumerator|Reference
name|Reference
block|}
enum|;
DECL|member|type
name|QString
name|type
decl_stmt|;
DECL|member|name
name|QString
name|name
decl_stmt|;
DECL|member|direction
name|Direction
name|direction
decl_stmt|;
DECL|member|mode
name|Mode
name|mode
decl_stmt|;
block|}
struct|;
end_struct
begin_struct
DECL|struct|Function
struct|struct
name|Function
block|{
DECL|member|returnType
name|QString
name|returnType
decl_stmt|;
DECL|member|name
name|QString
name|name
decl_stmt|;
DECL|member|arguments
name|QList
operator|<
name|Argument
operator|>
name|arguments
expr_stmt|;
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|FunctionList
typedef|typedef
name|QList
operator|<
name|Function
operator|>
name|FunctionList
expr_stmt|;
end_typedef
begin_typedef
DECL|typedef|VersionProfile
DECL|typedef|FunctionCollection
typedef|typedef
name|QMap
operator|<
name|VersionProfile
operator|,
name|FunctionList
operator|>
name|FunctionCollection
expr_stmt|;
end_typedef
begin_decl_stmt
name|class
name|SpecParser
block|{
name|public
label|:
name|explicit
name|SpecParser
parameter_list|()
function_decl|;
name|QString
name|specFileName
argument_list|()
specifier|const
block|{
return|return
name|m_specFileName
return|;
block|}
name|QString
name|typeMapFileName
argument_list|()
specifier|const
block|{
return|return
name|m_typeMapFileName
return|;
block|}
name|QList
operator|<
name|Version
operator|>
name|versions
argument_list|()
specifier|const
block|{
return|return
name|m_versions
return|;
block|}
name|QList
operator|<
name|VersionProfile
operator|>
name|versionProfiles
argument_list|()
specifier|const
block|{
return|return
name|m_functions
operator|.
name|uniqueKeys
argument_list|()
return|;
block|}
name|QList
operator|<
name|Function
operator|>
name|functionsForVersion
argument_list|(
argument|const VersionProfile&v
argument_list|)
specifier|const
block|{
return|return
name|m_functions
operator|.
name|values
argument_list|(
name|v
argument_list|)
return|;
block|}
name|QStringList
name|extensions
argument_list|()
specifier|const
block|{
return|return
name|QStringList
argument_list|(
name|m_extensionFunctions
operator|.
name|uniqueKeys
argument_list|()
argument_list|)
return|;
block|}
name|QList
operator|<
name|Function
operator|>
name|functionsForExtension
argument_list|(
argument|const QString&extension
argument_list|)
block|{
return|return
name|m_extensionFunctions
operator|.
name|values
argument_list|(
name|extension
argument_list|)
return|;
block|}
name|void
name|setSpecFileName
parameter_list|(
name|QString
name|arg
parameter_list|)
block|{
name|m_specFileName
operator|=
name|arg
expr_stmt|;
block|}
name|void
name|setTypeMapFileName
parameter_list|(
name|QString
name|arg
parameter_list|)
block|{
name|m_typeMapFileName
operator|=
name|arg
expr_stmt|;
block|}
name|void
name|parse
parameter_list|()
function_decl|;
name|protected
label|:
name|bool
name|parseTypeMap
parameter_list|()
function_decl|;
name|void
name|parseEnums
parameter_list|()
function_decl|;
name|void
name|parseFunctions
parameter_list|(
name|QTextStream
modifier|&
name|stream
parameter_list|)
function_decl|;
name|private
label|:
name|QString
name|m_specFileName
decl_stmt|;
name|QString
name|m_typeMapFileName
decl_stmt|;
name|QMap
operator|<
name|QString
operator|,
name|QString
operator|>
name|m_typeMap
expr_stmt|;
name|QMultiMap
operator|<
name|VersionProfile
operator|,
name|Function
operator|>
name|m_functions
expr_stmt|;
name|QList
operator|<
name|Version
operator|>
name|m_versions
expr_stmt|;
comment|// Extension support
name|QMultiMap
operator|<
name|QString
operator|,
name|Function
operator|>
name|m_extensionFunctions
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// SPECPARSER_H
end_comment
end_unit
