begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QREGEXP_H
end_ifndef
begin_define
DECL|macro|QREGEXP_H
define|#
directive|define
name|QREGEXP_H
end_define
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_REGEXP
end_ifndef
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_struct_decl
struct_decl|struct
name|QRegExpPrivate
struct_decl|;
end_struct_decl
begin_decl_stmt
DECL|variable|QStringList
name|class
name|QStringList
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QRegExp
block|{
name|public
label|:
enum|enum
name|PatternSyntax
block|{
name|RegExp
block|,
name|Wildcard
block|,
name|FixedString
block|,
name|RegExp2
block|,
name|WildcardUnix
block|,
name|W3CXmlSchema11
block|}
enum|;
enum|enum
name|CaretMode
block|{
name|CaretAtZero
block|,
name|CaretAtOffset
block|,
name|CaretWontMatch
block|}
enum|;
name|QRegExp
argument_list|()
expr_stmt|;
name|explicit
name|QRegExp
argument_list|(
specifier|const
name|QString
operator|&
name|pattern
argument_list|,
name|Qt
operator|::
name|CaseSensitivity
name|cs
operator|=
name|Qt
operator|::
name|CaseSensitive
argument_list|,
name|PatternSyntax
name|syntax
operator|=
name|RegExp
argument_list|)
decl_stmt|;
name|QRegExp
argument_list|(
specifier|const
name|QRegExp
operator|&
name|rx
argument_list|)
expr_stmt|;
operator|~
name|QRegExp
argument_list|()
expr_stmt|;
name|QRegExp
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QRegExp
operator|&
name|rx
operator|)
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
specifier|inline
name|QRegExp
modifier|&
name|operator
init|=
operator|(
name|QRegExp
operator|&&
name|other
operator|)
block|{
name|qSwap
argument_list|(
name|priv
argument_list|,
name|other
operator|.
name|priv
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
endif|#
directive|endif
specifier|inline
name|void
name|swap
parameter_list|(
name|QRegExp
modifier|&
name|other
parameter_list|)
block|{
name|qSwap
argument_list|(
name|priv
argument_list|,
name|other
operator|.
name|priv
argument_list|)
expr_stmt|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QRegExp
operator|&
name|rx
operator|)
specifier|const
expr_stmt|;
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QRegExp
operator|&
name|rx
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|rx
operator|)
return|;
block|}
name|bool
name|isEmpty
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isValid
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|pattern
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setPattern
parameter_list|(
specifier|const
name|QString
modifier|&
name|pattern
parameter_list|)
function_decl|;
name|Qt
operator|::
name|CaseSensitivity
name|caseSensitivity
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setCaseSensitivity
argument_list|(
name|Qt
operator|::
name|CaseSensitivity
name|cs
argument_list|)
decl_stmt|;
name|PatternSyntax
name|patternSyntax
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setPatternSyntax
parameter_list|(
name|PatternSyntax
name|syntax
parameter_list|)
function_decl|;
name|bool
name|isMinimal
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setMinimal
parameter_list|(
name|bool
name|minimal
parameter_list|)
function_decl|;
name|bool
name|exactMatch
argument_list|(
specifier|const
name|QString
operator|&
name|str
argument_list|)
decl|const
decl_stmt|;
name|int
name|indexIn
argument_list|(
specifier|const
name|QString
operator|&
name|str
argument_list|,
name|int
name|offset
operator|=
literal|0
argument_list|,
name|CaretMode
name|caretMode
operator|=
name|CaretAtZero
argument_list|)
decl|const
decl_stmt|;
name|int
name|lastIndexIn
argument_list|(
specifier|const
name|QString
operator|&
name|str
argument_list|,
name|int
name|offset
operator|=
operator|-
literal|1
argument_list|,
name|CaretMode
name|caretMode
operator|=
name|CaretAtZero
argument_list|)
decl|const
decl_stmt|;
name|int
name|matchedLength
argument_list|()
specifier|const
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_REGEXP_CAPTURE
name|int
name|captureCount
argument_list|()
specifier|const
expr_stmt|;
name|QStringList
name|capturedTexts
argument_list|()
specifier|const
expr_stmt|;
name|QStringList
name|capturedTexts
parameter_list|()
function_decl|;
name|QString
name|cap
argument_list|(
name|int
name|nth
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
name|QString
name|cap
parameter_list|(
name|int
name|nth
init|=
literal|0
parameter_list|)
function_decl|;
name|int
name|pos
argument_list|(
name|int
name|nth
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
name|int
name|pos
parameter_list|(
name|int
name|nth
init|=
literal|0
parameter_list|)
function_decl|;
name|QString
name|errorString
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|errorString
parameter_list|()
function_decl|;
endif|#
directive|endif
specifier|static
name|QString
name|escape
parameter_list|(
specifier|const
name|QString
modifier|&
name|str
parameter_list|)
function_decl|;
name|private
label|:
name|QRegExpPrivate
modifier|*
name|priv
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QRegExp
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_expr_stmt
name|Q_CORE_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
name|out
operator|,
specifier|const
name|QRegExp
operator|&
name|regExp
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_CORE_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
name|in
operator|,
name|QRegExp
operator|&
name|regExp
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_expr_stmt
name|Q_CORE_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
operator|,
specifier|const
name|QRegExp
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_REGEXP
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QREGEXP_H
end_comment
end_unit
