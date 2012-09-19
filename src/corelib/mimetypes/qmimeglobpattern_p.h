begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QMIMEGLOBPATTERN_P_H
end_ifndef
begin_define
DECL|macro|QMIMEGLOBPATTERN_P_H
define|#
directive|define
name|QMIMEGLOBPATTERN_P_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qstringlist.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qhash.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_struct
DECL|struct|QMimeGlobMatchResult
struct|struct
name|QMimeGlobMatchResult
block|{
DECL|function|QMimeGlobMatchResult
name|QMimeGlobMatchResult
argument_list|()
operator|:
name|m_weight
argument_list|(
literal|0
argument_list|)
operator|,
name|m_matchingPatternLength
argument_list|(
literal|0
argument_list|)
block|{}
name|void
name|addMatch
argument_list|(
argument|const QString&mimeType
argument_list|,
argument|int weight
argument_list|,
argument|const QString&pattern
argument_list|)
expr_stmt|;
DECL|member|m_matchingMimeTypes
name|QStringList
name|m_matchingMimeTypes
decl_stmt|;
DECL|member|m_weight
name|int
name|m_weight
decl_stmt|;
DECL|member|m_matchingPatternLength
name|int
name|m_matchingPatternLength
decl_stmt|;
DECL|member|m_foundSuffix
name|QString
name|m_foundSuffix
decl_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
name|class
name|QMimeGlobPattern
block|{
name|public
label|:
specifier|static
specifier|const
name|unsigned
name|MaxWeight
init|=
literal|100
decl_stmt|;
specifier|static
specifier|const
name|unsigned
name|DefaultWeight
init|=
literal|50
decl_stmt|;
specifier|static
specifier|const
name|unsigned
name|MinWeight
init|=
literal|1
decl_stmt|;
name|explicit
name|QMimeGlobPattern
argument_list|(
specifier|const
name|QString
operator|&
name|thePattern
argument_list|,
specifier|const
name|QString
operator|&
name|theMimeType
argument_list|,
name|unsigned
name|theWeight
operator|=
name|DefaultWeight
argument_list|,
name|Qt
operator|::
name|CaseSensitivity
name|s
operator|=
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
range|:
name|m_pattern
argument_list|(
name|thePattern
argument_list|)
decl_stmt|,
name|m_mimeType
argument_list|(
name|theMimeType
argument_list|)
decl_stmt|,
name|m_weight
argument_list|(
name|theWeight
argument_list|)
decl_stmt|,
name|m_caseSensitivity
argument_list|(
name|s
argument_list|)
block|{
if|if
condition|(
name|s
operator|==
name|Qt
operator|::
name|CaseInsensitive
condition|)
block|{
name|m_pattern
operator|=
name|m_pattern
operator|.
name|toLower
argument_list|()
expr_stmt|;
block|}
block|}
operator|~
name|QMimeGlobPattern
argument_list|()
block|{}
name|bool
name|matchFileName
argument_list|(
argument|const QString&filename
argument_list|)
specifier|const
expr_stmt|;
specifier|inline
specifier|const
name|QString
operator|&
name|pattern
argument_list|()
specifier|const
block|{
return|return
name|m_pattern
return|;
block|}
specifier|inline
name|unsigned
name|weight
argument_list|()
specifier|const
block|{
return|return
name|m_weight
return|;
block|}
specifier|inline
specifier|const
name|QString
operator|&
name|mimeType
argument_list|()
specifier|const
block|{
return|return
name|m_mimeType
return|;
block|}
specifier|inline
name|bool
name|isCaseSensitive
argument_list|()
specifier|const
block|{
return|return
name|m_caseSensitivity
operator|==
name|Qt
operator|::
name|CaseSensitive
return|;
block|}
name|private
label|:
name|QString
name|m_pattern
decl_stmt|;
name|QString
name|m_mimeType
decl_stmt|;
name|int
name|m_weight
decl_stmt|;
name|Qt
operator|::
name|CaseSensitivity
name|m_caseSensitivity
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QMimeGlobPatternList
range|:
name|public
name|QList
operator|<
name|QMimeGlobPattern
operator|>
block|{
name|public
operator|:
name|bool
name|hasPattern
argument_list|(
argument|const QString&mimeType
argument_list|,
argument|const QString&pattern
argument_list|)
specifier|const
block|{
name|const_iterator
name|it
operator|=
name|begin
argument_list|()
block|;
specifier|const
name|const_iterator
name|myend
operator|=
name|end
argument_list|()
block|;
for|for
control|(
init|;
name|it
operator|!=
name|myend
condition|;
operator|++
name|it
control|)
if|if
condition|(
operator|(
operator|*
name|it
operator|)
operator|.
name|pattern
argument_list|()
operator|==
name|pattern
operator|&&
operator|(
operator|*
name|it
operator|)
operator|.
name|mimeType
argument_list|()
operator|==
name|mimeType
condition|)
return|return
name|true
return|;
return|return
name|false
return|;
block|}
end_decl_stmt
begin_comment
comment|/*!         "noglobs" is very rare occurrence, so it's ok if it's slow      */
end_comment
begin_function
name|void
name|removeMimeType
parameter_list|(
specifier|const
name|QString
modifier|&
name|mimeType
parameter_list|)
block|{
name|QMutableListIterator
operator|<
name|QMimeGlobPattern
operator|>
name|it
argument_list|(
operator|*
name|this
argument_list|)
expr_stmt|;
while|while
condition|(
name|it
operator|.
name|hasNext
argument_list|()
condition|)
block|{
if|if
condition|(
name|it
operator|.
name|next
argument_list|()
operator|.
name|mimeType
argument_list|()
operator|==
name|mimeType
condition|)
name|it
operator|.
name|remove
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_decl_stmt
name|void
name|match
argument_list|(
name|QMimeGlobMatchResult
operator|&
name|result
argument_list|,
specifier|const
name|QString
operator|&
name|fileName
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_comment
unit|};
comment|/*!     Result of the globs parsing, as data structures ready for efficient MIME type matching.     This contains:     1) a map of fast regular patterns (e.g. *.txt is stored as "txt" in a qhash's key)     2) a linear list of high-weight globs     3) a linear list of low-weight globs  */
end_comment
begin_decl_stmt
name|class
name|QMimeAllGlobPatterns
block|{
name|public
label|:
typedef|typedef
name|QHash
operator|<
name|QString
operator|,
name|QStringList
operator|>
name|PatternsMap
expr_stmt|;
comment|// MIME type -> patterns
name|void
name|addGlob
parameter_list|(
specifier|const
name|QMimeGlobPattern
modifier|&
name|glob
parameter_list|)
function_decl|;
name|void
name|removeMimeType
parameter_list|(
specifier|const
name|QString
modifier|&
name|mimeType
parameter_list|)
function_decl|;
name|QStringList
name|matchingGlobs
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|,
name|QString
operator|*
name|foundSuffix
argument_list|)
decl|const
decl_stmt|;
name|void
name|clear
parameter_list|()
function_decl|;
name|PatternsMap
name|m_fastPatterns
decl_stmt|;
comment|// example: "doc" -> "application/msword", "text/plain"
name|QMimeGlobPatternList
name|m_highWeightGlobs
decl_stmt|;
name|QMimeGlobPatternList
name|m_lowWeightGlobs
decl_stmt|;
comment|//<= 50, including the non-fast 50 patterns
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QMIMEGLOBPATTERN_P_H
end_comment
end_unit
