begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_define
DECL|macro|QT_NO_CAST_FROM_ASCII
define|#
directive|define
name|QT_NO_CAST_FROM_ASCII
end_define
begin_include
include|#
directive|include
file|"qmimemagicrulematcher_p.h"
end_include
begin_include
include|#
directive|include
file|"qmimetype_p.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \internal     \class QMimeMagicRuleMatcher      \brief The QMimeMagicRuleMatcher class checks a number of rules based on operator "or".      It is used for rules parsed from XML files.      \sa QMimeType, QMimeDatabase, MagicRule, MagicStringRule, MagicByteRule, GlobPattern     \sa QMimeTypeParserBase, MimeTypeParser */
end_comment
begin_constructor
DECL|function|QMimeMagicRuleMatcher
name|QMimeMagicRuleMatcher
operator|::
name|QMimeMagicRuleMatcher
parameter_list|(
specifier|const
name|QString
modifier|&
name|mime
parameter_list|,
name|unsigned
name|thePriority
parameter_list|)
member_init_list|:
name|m_list
argument_list|()
member_init_list|,
name|m_priority
argument_list|(
name|thePriority
argument_list|)
member_init_list|,
name|m_mimetype
argument_list|(
name|mime
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|operator ==
name|bool
name|QMimeMagicRuleMatcher
operator|::
name|operator
name|==
parameter_list|(
specifier|const
name|QMimeMagicRuleMatcher
modifier|&
name|other
parameter_list|)
block|{
return|return
name|m_list
operator|==
name|other
operator|.
name|m_list
operator|&&
name|m_priority
operator|==
name|other
operator|.
name|m_priority
return|;
block|}
end_function
begin_function
DECL|function|addRule
name|void
name|QMimeMagicRuleMatcher
operator|::
name|addRule
parameter_list|(
specifier|const
name|QMimeMagicRule
modifier|&
name|rule
parameter_list|)
block|{
name|m_list
operator|.
name|append
argument_list|(
name|rule
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addRules
name|void
name|QMimeMagicRuleMatcher
operator|::
name|addRules
parameter_list|(
specifier|const
name|QList
argument_list|<
name|QMimeMagicRule
argument_list|>
modifier|&
name|rules
parameter_list|)
block|{
name|m_list
operator|.
name|append
argument_list|(
name|rules
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|magicRules
name|QList
argument_list|<
name|QMimeMagicRule
argument_list|>
name|QMimeMagicRuleMatcher
operator|::
name|magicRules
parameter_list|()
specifier|const
block|{
return|return
name|m_list
return|;
block|}
end_function
begin_comment
comment|// Check for a match on contents of a file
end_comment
begin_function
DECL|function|matches
name|bool
name|QMimeMagicRuleMatcher
operator|::
name|matches
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|data
parameter_list|)
specifier|const
block|{
foreach|foreach
control|(
specifier|const
name|QMimeMagicRule
modifier|&
name|magicRule
decl|,
name|m_list
control|)
block|{
if|if
condition|(
name|magicRule
operator|.
name|matches
argument_list|(
name|data
argument_list|)
condition|)
return|return
literal|true
return|;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|// Return a priority value from 1..100
end_comment
begin_function
DECL|function|priority
name|unsigned
name|QMimeMagicRuleMatcher
operator|::
name|priority
parameter_list|()
specifier|const
block|{
return|return
name|m_priority
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
