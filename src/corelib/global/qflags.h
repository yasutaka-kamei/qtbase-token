begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QFLAGS_H
end_ifndef
begin_define
DECL|macro|QFLAGS_H
define|#
directive|define
name|QFLAGS_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qtypeinfo.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qtypetraits.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_COMPILER_INITIALIZER_LISTS
end_ifdef
begin_include
include|#
directive|include
file|<initializer_list>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QFlag
block|{
name|int
name|i
decl_stmt|;
name|public
label|:
name|Q_DECL_CONSTEXPR
specifier|inline
name|QFlag
argument_list|(
argument|int ai
argument_list|)
operator|:
name|i
argument_list|(
argument|ai
argument_list|)
block|{}
name|Q_DECL_CONSTEXPR
specifier|inline
name|operator
name|int
argument_list|()
specifier|const
block|{
return|return
name|i
return|;
block|}
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_CC_MSVC
argument_list|)
comment|// Microsoft Visual Studio has buggy behavior when it comes to
comment|// unsigned enums: even if the enum is unsigned, the enum tags are
comment|// always signed
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__LP64__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_QDOC
argument_list|)
name|Q_DECL_CONSTEXPR
specifier|inline
name|QFlag
argument_list|(
argument|long ai
argument_list|)
operator|:
name|i
argument_list|(
argument|int(ai)
argument_list|)
block|{}
name|Q_DECL_CONSTEXPR
specifier|inline
name|QFlag
argument_list|(
argument|ulong ai
argument_list|)
operator|:
name|i
argument_list|(
argument|int(long(ai))
argument_list|)
block|{}
endif|#
directive|endif
name|Q_DECL_CONSTEXPR
specifier|inline
name|QFlag
argument_list|(
argument|uint ai
argument_list|)
operator|:
name|i
argument_list|(
argument|int(ai)
argument_list|)
block|{}
name|Q_DECL_CONSTEXPR
specifier|inline
name|QFlag
argument_list|(
argument|short ai
argument_list|)
operator|:
name|i
argument_list|(
argument|int(ai)
argument_list|)
block|{}
name|Q_DECL_CONSTEXPR
specifier|inline
name|QFlag
argument_list|(
argument|ushort ai
argument_list|)
operator|:
name|i
argument_list|(
argument|int(uint(ai))
argument_list|)
block|{}
name|Q_DECL_CONSTEXPR
specifier|inline
name|operator
name|uint
argument_list|()
specifier|const
block|{
return|return
name|uint
argument_list|(
name|i
argument_list|)
return|;
block|}
endif|#
directive|endif
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QFlag
argument_list|,
name|Q_PRIMITIVE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|class
name|QIncompatibleFlag
block|{
name|int
name|i
decl_stmt|;
name|public
label|:
name|Q_DECL_CONSTEXPR
specifier|inline
name|explicit
name|QIncompatibleFlag
parameter_list|(
name|int
name|i
parameter_list|)
function_decl|;
name|Q_DECL_CONSTEXPR
specifier|inline
name|operator
name|int
argument_list|()
specifier|const
block|{
return|return
name|i
return|;
block|}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QIncompatibleFlag
argument_list|,
name|Q_PRIMITIVE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|function|QIncompatibleFlag
name|Q_DECL_CONSTEXPR
specifier|inline
name|QIncompatibleFlag
operator|::
name|QIncompatibleFlag
argument_list|(
argument|int ai
argument_list|)
operator|:
name|i
argument_list|(
argument|ai
argument_list|)
block|{}
ifndef|#
directive|ifndef
name|Q_NO_TYPESAFE_FLAGS
name|template
operator|<
name|typename
name|Enum
operator|>
name|class
name|QFlags
block|{
name|Q_STATIC_ASSERT_X
argument_list|(
operator|(
sizeof|sizeof
argument_list|(
name|Enum
argument_list|)
operator|<=
sizeof|sizeof
argument_list|(
name|int
argument_list|)
operator|)
argument_list|,
literal|"QFlags uses an int as storage, so an enum with underlying "
literal|"long long will overflow."
argument_list|)
block|;     struct
name|Private
block|;
typedef|typedef
name|int
argument_list|(
name|Private
operator|::
operator|*
name|Zero
argument_list|)
expr_stmt|;
name|public
operator|:
end_expr_stmt
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_CC_MSVC
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_QDOC
argument_list|)
end_if
begin_comment
comment|// see above for MSVC
end_comment
begin_comment
comment|// the definition below is too complex for qdoc
end_comment
begin_typedef
typedef|typedef
name|int
name|Int
typedef|;
end_typedef
begin_else
else|#
directive|else
end_else
begin_typedef
typedef|typedef
name|typename
name|QtPrivate
operator|::
name|if_
operator|<
name|QtPrivate
operator|::
name|is_unsigned
operator|<
name|Enum
operator|>
operator|::
name|value
operator|,
name|unsigned
name|int
operator|,
name|signed
name|int
operator|>
operator|::
name|type
name|Int
expr_stmt|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_typedef
typedef|typedef
name|Enum
name|enum_type
typedef|;
end_typedef
begin_comment
comment|// compiler-generated copy/move ctor/assignment operators are fine!
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|Q_QDOC
end_ifdef
begin_expr_stmt
specifier|inline
name|QFlags
argument_list|(
specifier|const
name|QFlags
operator|&
name|other
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
specifier|inline
name|QFlags
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QFlags
operator|&
name|other
operator|)
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|Q_DECL_CONSTEXPR
end_macro
begin_expr_stmt
specifier|inline
name|QFlags
argument_list|(
argument|Enum f
argument_list|)
operator|:
name|i
argument_list|(
argument|Int(f)
argument_list|)
block|{}
name|Q_DECL_CONSTEXPR
specifier|inline
name|QFlags
argument_list|(
name|Zero
operator|=
literal|0
argument_list|)
operator|:
name|i
argument_list|(
literal|0
argument_list|)
block|{}
name|Q_DECL_CONSTEXPR
specifier|inline
name|QFlags
argument_list|(
argument|QFlag f
argument_list|)
operator|:
name|i
argument_list|(
argument|f
argument_list|)
block|{}
ifdef|#
directive|ifdef
name|Q_COMPILER_INITIALIZER_LISTS
name|Q_DECL_CONSTEXPR
specifier|inline
name|QFlags
argument_list|(
name|std
operator|::
name|initializer_list
operator|<
name|Enum
operator|>
name|flags
argument_list|)
operator|:
name|i
argument_list|(
argument|initializer_list_helper(flags.begin(), flags.end())
argument_list|)
block|{}
endif|#
directive|endif
specifier|inline
name|QFlags
operator|&
name|operator
operator|&=
operator|(
name|int
name|mask
operator|)
block|{
name|i
operator|&=
name|mask
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QFlags
operator|&
name|operator
operator|&=
operator|(
name|uint
name|mask
operator|)
block|{
name|i
operator|&=
name|mask
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QFlags
operator|&
name|operator
operator|&=
operator|(
name|Enum
name|mask
operator|)
block|{
name|i
operator|&=
name|Int
argument_list|(
name|mask
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QFlags
operator|&
name|operator
operator||=
operator|(
name|QFlags
name|f
operator|)
block|{
name|i
operator||=
name|f
operator|.
name|i
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QFlags
operator|&
name|operator
operator||=
operator|(
name|Enum
name|f
operator|)
block|{
name|i
operator||=
name|Int
argument_list|(
name|f
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QFlags
operator|&
name|operator
operator|^=
operator|(
name|QFlags
name|f
operator|)
block|{
name|i
operator|^=
name|f
operator|.
name|i
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QFlags
operator|&
name|operator
operator|^=
operator|(
name|Enum
name|f
operator|)
block|{
name|i
operator|^=
name|Int
argument_list|(
name|f
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|operator
name|Int
argument_list|()
specifier|const
block|{
return|return
name|i
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|QFlags
name|operator
operator||
operator|(
name|QFlags
name|f
operator|)
specifier|const
block|{
return|return
name|QFlags
argument_list|(
name|QFlag
argument_list|(
name|i
operator||
name|f
operator|.
name|i
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|QFlags
name|operator
operator||
operator|(
name|Enum
name|f
operator|)
specifier|const
block|{
return|return
name|QFlags
argument_list|(
name|QFlag
argument_list|(
name|i
operator||
name|Int
argument_list|(
name|f
argument_list|)
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_decl_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|QFlags
name|operator
modifier|^
argument_list|(
name|QFlags
name|f
argument_list|)
decl|const
block|{
return|return
name|QFlags
argument_list|(
name|QFlag
argument_list|(
name|i
operator|^
name|f
operator|.
name|i
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt
begin_decl_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|QFlags
name|operator
modifier|^
argument_list|(
name|Enum
name|f
argument_list|)
decl|const
block|{
return|return
name|QFlags
argument_list|(
name|QFlag
argument_list|(
name|i
operator|^
name|Int
argument_list|(
name|f
argument_list|)
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt
begin_decl_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|QFlags
name|operator
modifier|&
argument_list|(
name|int
name|mask
argument_list|)
decl|const
block|{
return|return
name|QFlags
argument_list|(
name|QFlag
argument_list|(
name|i
operator|&
name|mask
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt
begin_decl_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|QFlags
name|operator
modifier|&
argument_list|(
name|uint
name|mask
argument_list|)
decl|const
block|{
return|return
name|QFlags
argument_list|(
name|QFlag
argument_list|(
name|i
operator|&
name|mask
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt
begin_decl_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|QFlags
name|operator
modifier|&
argument_list|(
name|Enum
name|f
argument_list|)
decl|const
block|{
return|return
name|QFlags
argument_list|(
name|QFlag
argument_list|(
name|i
operator|&
name|Int
argument_list|(
name|f
argument_list|)
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|QFlags
name|operator
operator|~
operator|(
operator|)
specifier|const
block|{
return|return
name|QFlags
argument_list|(
name|QFlag
argument_list|(
operator|~
name|i
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|operator
operator|!
operator|(
operator|)
specifier|const
block|{
return|return
operator|!
name|i
return|;
block|}
end_expr_stmt
begin_decl_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|testFlag
argument_list|(
name|Enum
name|f
argument_list|)
decl|const
block|{
return|return
operator|(
name|i
operator|&
name|Int
argument_list|(
name|f
argument_list|)
operator|)
operator|==
name|Int
argument_list|(
name|f
argument_list|)
operator|&&
operator|(
name|Int
argument_list|(
name|f
argument_list|)
operator|!=
literal|0
operator|||
name|i
operator|==
name|Int
argument_list|(
name|f
argument_list|)
operator|)
return|;
block|}
end_decl_stmt
begin_label
name|private
label|:
end_label
begin_ifdef
ifdef|#
directive|ifdef
name|Q_COMPILER_INITIALIZER_LISTS
end_ifdef
begin_decl_stmt
name|Q_DECL_CONSTEXPR
specifier|static
specifier|inline
name|Int
name|initializer_list_helper
argument_list|(
name|typename
name|std
operator|::
name|initializer_list
operator|<
name|Enum
operator|>
operator|::
name|const_iterator
name|it
argument_list|,
name|typename
name|std
operator|::
name|initializer_list
operator|<
name|Enum
operator|>
operator|::
name|const_iterator
name|end
argument_list|)
block|{
return|return
operator|(
name|it
operator|==
name|end
condition|?
name|Int
argument_list|(
literal|0
argument_list|)
else|:
operator|(
name|Int
argument_list|(
operator|*
name|it
argument_list|)
operator||
name|initializer_list_helper
argument_list|(
name|it
operator|+
literal|1
argument_list|,
name|end
argument_list|)
operator|)
operator|)
return|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|Int
name|i
decl_stmt|;
end_decl_stmt
begin_define
DECL|macro|Q_DECLARE_FLAGS
unit|};
define|#
directive|define
name|Q_DECLARE_FLAGS
parameter_list|(
name|Flags
parameter_list|,
name|Enum
parameter_list|)
define|\
value|typedef QFlags<Enum> Flags;
end_define
begin_define
DECL|macro|Q_DECLARE_INCOMPATIBLE_FLAGS
define|#
directive|define
name|Q_DECLARE_INCOMPATIBLE_FLAGS
parameter_list|(
name|Flags
parameter_list|)
define|\
value|Q_DECL_CONSTEXPR inline QIncompatibleFlag operator|(Flags::enum_type f1, int f2) \ { return QIncompatibleFlag(int(f1) | f2); }
end_define
begin_define
DECL|macro|Q_DECLARE_OPERATORS_FOR_FLAGS
define|#
directive|define
name|Q_DECLARE_OPERATORS_FOR_FLAGS
parameter_list|(
name|Flags
parameter_list|)
define|\
value|Q_DECL_CONSTEXPR inline QFlags<Flags::enum_type> operator|(Flags::enum_type f1, Flags::enum_type f2) \ { return QFlags<Flags::enum_type>(f1) | f2; } \ Q_DECL_CONSTEXPR inline QFlags<Flags::enum_type> operator|(Flags::enum_type f1, QFlags<Flags::enum_type> f2) \ { return f2 | f1; } Q_DECLARE_INCOMPATIBLE_FLAGS(Flags)
end_define
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* Q_NO_TYPESAFE_FLAGS */
end_comment
begin_define
DECL|macro|Q_DECLARE_FLAGS
define|#
directive|define
name|Q_DECLARE_FLAGS
parameter_list|(
name|Flags
parameter_list|,
name|Enum
parameter_list|)
define|\
value|typedef uint Flags;
end_define
begin_define
DECL|macro|Q_DECLARE_OPERATORS_FOR_FLAGS
define|#
directive|define
name|Q_DECLARE_OPERATORS_FOR_FLAGS
parameter_list|(
name|Flags
parameter_list|)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* Q_NO_TYPESAFE_FLAGS */
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QFLAGS_H
end_comment
end_unit
