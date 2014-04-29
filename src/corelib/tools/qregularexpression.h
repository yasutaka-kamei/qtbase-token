begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Giuseppe D'Angelo<dangelog@gmail.com>. ** Copyright (C) 2012 KlarÃ¤lvdalens Datakonsult AB, a KDAB Group company, info@kdab.com, author Giuseppe D'Angelo<giuseppe.dangelo@kdab.com> ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QREGULAREXPRESSION_H
end_ifndef
begin_define
DECL|macro|QREGULAREXPRESSION_H
define|#
directive|define
name|QREGULAREXPRESSION_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_REGULAREXPRESSION
end_ifndef
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstringlist.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qshareddata.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvariant.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QRegularExpressionMatch
name|class
name|QRegularExpressionMatch
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QRegularExpressionMatchIterator
name|class
name|QRegularExpressionMatchIterator
decl_stmt|;
end_decl_stmt
begin_struct_decl
struct_decl|struct
name|QRegularExpressionPrivate
struct_decl|;
end_struct_decl
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QRegularExpression
block|{
name|public
label|:
enum|enum
name|PatternOption
block|{
name|NoPatternOption
init|=
literal|0x0000
block|,
name|CaseInsensitiveOption
init|=
literal|0x0001
block|,
name|DotMatchesEverythingOption
init|=
literal|0x0002
block|,
name|MultilineOption
init|=
literal|0x0004
block|,
name|ExtendedPatternSyntaxOption
init|=
literal|0x0008
block|,
name|InvertedGreedinessOption
init|=
literal|0x0010
block|,
name|DontCaptureOption
init|=
literal|0x0020
block|,
name|UseUnicodePropertiesOption
init|=
literal|0x0040
block|,
name|OptimizeOnFirstUsageOption
init|=
literal|0x0080
block|,
name|DontAutomaticallyOptimizeOption
init|=
literal|0x0100
block|}
enum|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|PatternOptions
argument_list|,
argument|PatternOption
argument_list|)
name|PatternOptions
name|patternOptions
parameter_list|()
function_decl|const;
name|void
name|setPatternOptions
parameter_list|(
name|PatternOptions
name|options
parameter_list|)
function_decl|;
name|QRegularExpression
argument_list|()
expr_stmt|;
name|explicit
name|QRegularExpression
parameter_list|(
specifier|const
name|QString
modifier|&
name|pattern
parameter_list|,
name|PatternOptions
name|options
init|=
name|NoPatternOption
parameter_list|)
function_decl|;
name|QRegularExpression
argument_list|(
specifier|const
name|QRegularExpression
operator|&
name|re
argument_list|)
expr_stmt|;
operator|~
name|QRegularExpression
argument_list|()
expr_stmt|;
name|QRegularExpression
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QRegularExpression
operator|&
name|re
operator|)
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
specifier|inline
name|QRegularExpression
modifier|&
name|operator
init|=
operator|(
name|QRegularExpression
operator|&&
name|re
operator|)
block|{
name|d
operator|.
name|swap
argument_list|(
name|re
operator|.
name|d
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
name|QRegularExpression
modifier|&
name|re
parameter_list|)
block|{
name|d
operator|.
name|swap
argument_list|(
name|re
operator|.
name|d
argument_list|)
expr_stmt|;
block|}
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
name|bool
name|isValid
argument_list|()
specifier|const
expr_stmt|;
name|int
name|patternErrorOffset
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|errorString
argument_list|()
specifier|const
expr_stmt|;
name|int
name|captureCount
argument_list|()
specifier|const
expr_stmt|;
name|QStringList
name|namedCaptureGroups
argument_list|()
specifier|const
expr_stmt|;
enum|enum
name|MatchType
block|{
name|NormalMatch
init|=
literal|0
block|,
name|PartialPreferCompleteMatch
block|,
name|PartialPreferFirstMatch
block|,
name|NoMatch
block|}
enum|;
enum|enum
name|MatchOption
block|{
name|NoMatchOption
init|=
literal|0x0000
block|,
name|AnchoredMatchOption
init|=
literal|0x0001
block|}
enum|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|MatchOptions
argument_list|,
argument|MatchOption
argument_list|)
name|QRegularExpressionMatch
name|match
argument_list|(
specifier|const
name|QString
operator|&
name|subject
argument_list|,
name|int
name|offset
operator|=
literal|0
argument_list|,
name|MatchType
name|matchType
operator|=
name|NormalMatch
argument_list|,
name|MatchOptions
name|matchOptions
operator|=
name|NoMatchOption
argument_list|)
decl|const
decl_stmt|;
name|QRegularExpressionMatchIterator
name|globalMatch
argument_list|(
specifier|const
name|QString
operator|&
name|subject
argument_list|,
name|int
name|offset
operator|=
literal|0
argument_list|,
name|MatchType
name|matchType
operator|=
name|NormalMatch
argument_list|,
name|MatchOptions
name|matchOptions
operator|=
name|NoMatchOption
argument_list|)
decl|const
decl_stmt|;
name|void
name|optimize
parameter_list|()
function_decl|;
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
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QRegularExpression
operator|&
name|re
operator|)
specifier|const
expr_stmt|;
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QRegularExpression
operator|&
name|re
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|re
operator|)
return|;
block|}
name|private
label|:
name|friend
struct_decl|struct
name|QRegularExpressionPrivate
struct_decl|;
name|friend
name|class
name|QRegularExpressionMatch
decl_stmt|;
name|friend
struct_decl|struct
name|QRegularExpressionMatchPrivate
struct_decl|;
name|friend
name|class
name|QRegularExpressionMatchIterator
decl_stmt|;
name|QRegularExpression
argument_list|(
name|QRegularExpressionPrivate
operator|&
name|dd
argument_list|)
expr_stmt|;
name|QExplicitlySharedDataPointer
operator|<
name|QRegularExpressionPrivate
operator|>
name|d
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|Q_DECLARE_SHARED
argument_list|(
argument|QRegularExpression
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QRegularExpression::PatternOptions
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QRegularExpression::MatchOptions
argument_list|)
end_macro
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
name|QRegularExpression
operator|&
name|re
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|operator
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
name|QRegularExpression
operator|&
name|re
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
name|debug
operator|,
specifier|const
name|QRegularExpression
operator|&
name|re
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_CORE_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
name|debug
operator|,
name|QRegularExpression
operator|::
name|PatternOptions
name|patternOptions
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_struct_decl
struct_decl|struct
name|QRegularExpressionMatchPrivate
struct_decl|;
end_struct_decl
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QRegularExpressionMatch
block|{
name|public
label|:
name|QRegularExpressionMatch
argument_list|()
expr_stmt|;
operator|~
name|QRegularExpressionMatch
argument_list|()
expr_stmt|;
name|QRegularExpressionMatch
argument_list|(
specifier|const
name|QRegularExpressionMatch
operator|&
name|match
argument_list|)
expr_stmt|;
name|QRegularExpressionMatch
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QRegularExpressionMatch
operator|&
name|match
operator|)
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
specifier|inline
name|QRegularExpressionMatch
modifier|&
name|operator
init|=
operator|(
name|QRegularExpressionMatch
operator|&&
name|match
operator|)
block|{
name|d
operator|.
name|swap
argument_list|(
name|match
operator|.
name|d
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
name|QRegularExpressionMatch
modifier|&
name|match
parameter_list|)
block|{
name|d
operator|.
name|swap
argument_list|(
name|match
operator|.
name|d
argument_list|)
expr_stmt|;
block|}
name|QRegularExpression
name|regularExpression
argument_list|()
specifier|const
expr_stmt|;
name|QRegularExpression
operator|::
name|MatchType
name|matchType
argument_list|()
specifier|const
expr_stmt|;
name|QRegularExpression
operator|::
name|MatchOptions
name|matchOptions
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|hasMatch
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|hasPartialMatch
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isValid
argument_list|()
specifier|const
expr_stmt|;
name|int
name|lastCapturedIndex
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|captured
argument_list|(
name|int
name|nth
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
name|QStringRef
name|capturedRef
argument_list|(
name|int
name|nth
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
name|QString
name|captured
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
decl|const
decl_stmt|;
name|QStringRef
name|capturedRef
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
decl|const
decl_stmt|;
name|QStringList
name|capturedTexts
argument_list|()
specifier|const
expr_stmt|;
name|int
name|capturedStart
argument_list|(
name|int
name|nth
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
name|int
name|capturedLength
argument_list|(
name|int
name|nth
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
name|int
name|capturedEnd
argument_list|(
name|int
name|nth
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
name|int
name|capturedStart
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
decl|const
decl_stmt|;
name|int
name|capturedLength
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
decl|const
decl_stmt|;
name|int
name|capturedEnd
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|friend
name|class
name|QRegularExpression
decl_stmt|;
name|friend
struct_decl|struct
name|QRegularExpressionMatchPrivate
struct_decl|;
name|friend
name|class
name|QRegularExpressionMatchIterator
decl_stmt|;
name|QRegularExpressionMatch
argument_list|(
name|QRegularExpressionMatchPrivate
operator|&
name|dd
argument_list|)
expr_stmt|;
name|QSharedDataPointer
operator|<
name|QRegularExpressionMatchPrivate
operator|>
name|d
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|Q_DECLARE_SHARED
argument_list|(
argument|QRegularExpressionMatch
argument_list|)
end_macro
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
name|debug
operator|,
specifier|const
name|QRegularExpressionMatch
operator|&
name|match
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_struct_decl
struct_decl|struct
name|QRegularExpressionMatchIteratorPrivate
struct_decl|;
end_struct_decl
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QRegularExpressionMatchIterator
block|{
name|public
label|:
name|QRegularExpressionMatchIterator
argument_list|()
expr_stmt|;
operator|~
name|QRegularExpressionMatchIterator
argument_list|()
expr_stmt|;
name|QRegularExpressionMatchIterator
argument_list|(
specifier|const
name|QRegularExpressionMatchIterator
operator|&
name|iterator
argument_list|)
expr_stmt|;
name|QRegularExpressionMatchIterator
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QRegularExpressionMatchIterator
operator|&
name|iterator
operator|)
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
specifier|inline
name|QRegularExpressionMatchIterator
modifier|&
name|operator
init|=
operator|(
name|QRegularExpressionMatchIterator
operator|&&
name|iterator
operator|)
block|{
name|d
operator|.
name|swap
argument_list|(
name|iterator
operator|.
name|d
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
endif|#
directive|endif
name|void
name|swap
parameter_list|(
name|QRegularExpressionMatchIterator
modifier|&
name|iterator
parameter_list|)
block|{
name|d
operator|.
name|swap
argument_list|(
name|iterator
operator|.
name|d
argument_list|)
expr_stmt|;
block|}
name|bool
name|isValid
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|hasNext
argument_list|()
specifier|const
expr_stmt|;
name|QRegularExpressionMatch
name|next
parameter_list|()
function_decl|;
name|QRegularExpressionMatch
name|peekNext
argument_list|()
specifier|const
expr_stmt|;
name|QRegularExpression
name|regularExpression
argument_list|()
specifier|const
expr_stmt|;
name|QRegularExpression
operator|::
name|MatchType
name|matchType
argument_list|()
specifier|const
expr_stmt|;
name|QRegularExpression
operator|::
name|MatchOptions
name|matchOptions
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|friend
name|class
name|QRegularExpression
decl_stmt|;
name|QRegularExpressionMatchIterator
argument_list|(
name|QRegularExpressionMatchIteratorPrivate
operator|&
name|dd
argument_list|)
expr_stmt|;
name|QSharedDataPointer
operator|<
name|QRegularExpressionMatchIteratorPrivate
operator|>
name|d
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|Q_DECLARE_SHARED
argument_list|(
argument|QRegularExpressionMatchIterator
argument_list|)
end_macro
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_REGULAREXPRESSION
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QREGULAREXPRESSION_H
end_comment
end_unit
