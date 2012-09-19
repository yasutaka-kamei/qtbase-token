begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QMIMETYPEPARSER_P_H
end_ifndef
begin_define
DECL|macro|QMIMETYPEPARSER_P_H
define|#
directive|define
name|QMIMETYPEPARSER_P_H
end_define
begin_include
include|#
directive|include
file|"qmimedatabase_p.h"
end_include
begin_include
include|#
directive|include
file|"qmimeprovider_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QIODevice
name|class
name|QIODevice
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QMimeTypeParserBase
block|{
name|Q_DISABLE_COPY
argument_list|(
argument|QMimeTypeParserBase
argument_list|)
name|public
label|:
name|QMimeTypeParserBase
argument_list|()
block|{}
name|virtual
operator|~
name|QMimeTypeParserBase
argument_list|()
block|{}
name|bool
name|parse
argument_list|(
name|QIODevice
operator|*
name|dev
argument_list|,
specifier|const
name|QString
operator|&
name|fileName
argument_list|,
name|QString
operator|*
name|errorMessage
argument_list|)
expr_stmt|;
name|protected
label|:
name|virtual
name|bool
name|process
parameter_list|(
specifier|const
name|QMimeType
modifier|&
name|t
parameter_list|,
name|QString
modifier|*
name|errorMessage
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|bool
name|process
parameter_list|(
specifier|const
name|QMimeGlobPattern
modifier|&
name|t
parameter_list|,
name|QString
modifier|*
name|errorMessage
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|processParent
parameter_list|(
specifier|const
name|QString
modifier|&
name|child
parameter_list|,
specifier|const
name|QString
modifier|&
name|parent
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|processAlias
parameter_list|(
specifier|const
name|QString
modifier|&
name|alias
parameter_list|,
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|processMagicMatcher
parameter_list|(
specifier|const
name|QMimeMagicRuleMatcher
modifier|&
name|matcher
parameter_list|)
init|=
literal|0
function_decl|;
name|private
label|:
enum|enum
name|ParseState
block|{
name|ParseBeginning
block|,
name|ParseMimeInfo
block|,
name|ParseMimeType
block|,
name|ParseComment
block|,
name|ParseGenericIcon
block|,
name|ParseIcon
block|,
name|ParseGlobPattern
block|,
name|ParseSubClass
block|,
name|ParseAlias
block|,
name|ParseMagic
block|,
name|ParseMagicMatchRule
block|,
name|ParseOtherMimeTypeSubTag
block|,
name|ParseError
block|}
enum|;
specifier|static
name|ParseState
name|nextState
parameter_list|(
name|ParseState
name|currentState
parameter_list|,
specifier|const
name|QStringRef
modifier|&
name|startElement
parameter_list|)
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QMimeTypeParser
range|:
name|public
name|QMimeTypeParserBase
block|{
name|public
operator|:
name|explicit
name|QMimeTypeParser
argument_list|(
name|QMimeXMLProvider
operator|&
name|provider
argument_list|)
operator|:
name|m_provider
argument_list|(
argument|provider
argument_list|)
block|{}
name|protected
operator|:
specifier|inline
name|bool
name|process
argument_list|(
argument|const QMimeType&t
argument_list|,
argument|QString *
argument_list|)
block|{
name|m_provider
operator|.
name|addMimeType
argument_list|(
name|t
argument_list|)
block|;
return|return
name|true
return|;
block|}
specifier|inline
name|bool
name|process
argument_list|(
argument|const QMimeGlobPattern&glob
argument_list|,
argument|QString *
argument_list|)
block|{
name|m_provider
operator|.
name|addGlobPattern
argument_list|(
name|glob
argument_list|)
block|;
return|return
name|true
return|;
block|}
specifier|inline
name|void
name|processParent
argument_list|(
argument|const QString&child
argument_list|,
argument|const QString&parent
argument_list|)
block|{
name|m_provider
operator|.
name|addParent
argument_list|(
name|child
argument_list|,
name|parent
argument_list|)
block|; }
specifier|inline
name|void
name|processAlias
argument_list|(
argument|const QString&alias
argument_list|,
argument|const QString&name
argument_list|)
block|{
name|m_provider
operator|.
name|addAlias
argument_list|(
name|alias
argument_list|,
name|name
argument_list|)
block|; }
specifier|inline
name|void
name|processMagicMatcher
argument_list|(
argument|const QMimeMagicRuleMatcher&matcher
argument_list|)
block|{
name|m_provider
operator|.
name|addMagicMatcher
argument_list|(
name|matcher
argument_list|)
block|; }
name|private
operator|:
name|QMimeXMLProvider
operator|&
name|m_provider
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// MIMETYPEPARSER_P_H
end_comment
end_unit
