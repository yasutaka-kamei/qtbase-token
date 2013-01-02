begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTEXTDOCUMENTFRAGMENT_P_H
end_ifndef
begin_define
DECL|macro|QTEXTDOCUMENTFRAGMENT_P_H
define|#
directive|define
name|QTEXTDOCUMENTFRAGMENT_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"QtGui/qtextdocument.h"
end_include
begin_include
include|#
directive|include
file|"private/qtexthtmlparser_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qtextdocument_p.h"
end_include
begin_include
include|#
directive|include
file|"QtGui/qtexttable.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qatomic.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qlist.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qmap.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qpointer.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qvarlengtharray.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qdatastream.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QTextDocumentFragmentPrivate
name|class
name|QTextDocumentFragmentPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QTextCopyHelper
block|{
name|public
label|:
name|QTextCopyHelper
argument_list|(
argument|const QTextCursor&_source
argument_list|,
argument|const QTextCursor&_destination
argument_list|,
argument|bool forceCharFormat = false
argument_list|,
argument|const QTextCharFormat&fmt = QTextCharFormat()
argument_list|)
empty_stmt|;
name|void
name|copy
parameter_list|()
function_decl|;
name|private
label|:
name|void
name|appendFragments
parameter_list|(
name|int
name|pos
parameter_list|,
name|int
name|endPos
parameter_list|)
function_decl|;
name|int
name|appendFragment
parameter_list|(
name|int
name|pos
parameter_list|,
name|int
name|endPos
parameter_list|,
name|int
name|objectIndex
init|=
operator|-
literal|1
parameter_list|)
function_decl|;
name|int
name|convertFormatIndex
parameter_list|(
specifier|const
name|QTextFormat
modifier|&
name|oldFormat
parameter_list|,
name|int
name|objectIndexToSet
init|=
operator|-
literal|1
parameter_list|)
function_decl|;
specifier|inline
name|int
name|convertFormatIndex
parameter_list|(
name|int
name|oldFormatIndex
parameter_list|,
name|int
name|objectIndexToSet
init|=
operator|-
literal|1
parameter_list|)
block|{
return|return
name|convertFormatIndex
argument_list|(
name|src
operator|->
name|formatCollection
argument_list|()
operator|->
name|format
argument_list|(
name|oldFormatIndex
argument_list|)
argument_list|,
name|objectIndexToSet
argument_list|)
return|;
block|}
specifier|inline
name|QTextFormat
name|convertFormat
parameter_list|(
specifier|const
name|QTextFormat
modifier|&
name|fmt
parameter_list|)
block|{
return|return
name|dst
operator|->
name|formatCollection
argument_list|()
operator|->
name|format
argument_list|(
name|convertFormatIndex
argument_list|(
name|fmt
argument_list|)
argument_list|)
return|;
block|}
name|int
name|insertPos
decl_stmt|;
name|bool
name|forceCharFormat
decl_stmt|;
name|int
name|primaryCharFormatIndex
decl_stmt|;
name|QTextCursor
name|cursor
decl_stmt|;
name|QTextDocumentPrivate
modifier|*
name|dst
decl_stmt|;
name|QTextDocumentPrivate
modifier|*
name|src
decl_stmt|;
name|QTextFormatCollection
modifier|&
name|formatCollection
decl_stmt|;
specifier|const
name|QString
name|originalText
decl_stmt|;
name|QMap
operator|<
name|int
operator|,
name|int
operator|>
name|objectIndexMap
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QTextDocumentFragmentPrivate
block|{
name|public
label|:
name|QTextDocumentFragmentPrivate
argument_list|(
specifier|const
name|QTextCursor
operator|&
name|cursor
operator|=
name|QTextCursor
argument_list|()
argument_list|)
expr_stmt|;
specifier|inline
operator|~
name|QTextDocumentFragmentPrivate
argument_list|()
block|{
name|delete
name|doc
block|; }
name|void
name|insert
argument_list|(
argument|QTextCursor&cursor
argument_list|)
specifier|const
expr_stmt|;
name|QAtomicInt
name|ref
decl_stmt|;
name|QTextDocument
modifier|*
name|doc
decl_stmt|;
name|uint
name|importedFromPlainText
range|:
literal|1
decl_stmt|;
name|private
label|:
name|Q_DISABLE_COPY
argument_list|(
argument|QTextDocumentFragmentPrivate
argument_list|)
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_TEXTHTMLPARSER
end_ifndef
begin_decl_stmt
name|class
name|QTextHtmlImporter
range|:
name|public
name|QTextHtmlParser
block|{     struct
name|Table
block|;
name|public
operator|:
expr|enum
name|ImportMode
block|{
name|ImportToFragment
block|,
name|ImportToDocument
block|}
block|;
name|QTextHtmlImporter
argument_list|(
argument|QTextDocument *_doc
argument_list|,
argument|const QString&html
argument_list|,
argument|ImportMode mode
argument_list|,
argument|const QTextDocument *resourceProvider =
literal|0
argument_list|)
block|;
name|void
name|import
argument_list|()
block|;
name|private
operator|:
name|bool
name|closeTag
argument_list|()
block|;
name|Table
name|scanTable
argument_list|(
argument|int tableNodeIdx
argument_list|)
block|;      enum
name|ProcessNodeResult
block|{
name|ContinueWithNextNode
block|,
name|ContinueWithCurrentNode
block|,
name|ContinueWithNextSibling
block|}
block|;
name|void
name|appendBlock
argument_list|(
argument|const QTextBlockFormat&format
argument_list|,
argument|QTextCharFormat charFmt = QTextCharFormat()
argument_list|)
block|;
name|bool
name|appendNodeText
argument_list|()
block|;
name|ProcessNodeResult
name|processBlockNode
argument_list|()
block|;
name|ProcessNodeResult
name|processSpecialNodes
argument_list|()
block|;      struct
name|List
block|{
specifier|inline
name|List
argument_list|()
operator|:
name|listNode
argument_list|(
literal|0
argument_list|)
block|{}
name|QTextListFormat
name|format
block|;
name|int
name|listNode
block|;
name|QPointer
operator|<
name|QTextList
operator|>
name|list
block|;     }
block|;
name|QVector
operator|<
name|List
operator|>
name|lists
block|;
name|int
name|indent
block|;
comment|// insert a named anchor the next time we emit a char format,
comment|// either in a block or in regular text
name|QStringList
name|namedAnchors
block|;
ifdef|#
directive|ifdef
name|Q_CC_SUN
name|friend
expr|struct
name|QTextHtmlImporter
operator|::
name|Table
block|;
endif|#
directive|endif
block|struct
name|TableCellIterator
block|{
specifier|inline
name|TableCellIterator
argument_list|(
name|QTextTable
operator|*
name|t
operator|=
literal|0
argument_list|)
operator|:
name|table
argument_list|(
name|t
argument_list|)
block|,
name|row
argument_list|(
literal|0
argument_list|)
block|,
name|column
argument_list|(
literal|0
argument_list|)
block|{}
specifier|inline
name|TableCellIterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
if|if
condition|(
name|atEnd
argument_list|()
condition|)
return|return
operator|*
name|this
return|;
do|do
block|{
specifier|const
name|QTextTableCell
name|cell
init|=
name|table
operator|->
name|cellAt
argument_list|(
name|row
argument_list|,
name|column
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|cell
operator|.
name|isValid
argument_list|()
condition|)
break|break;
name|column
operator|+=
name|cell
operator|.
name|columnSpan
argument_list|()
expr_stmt|;
if|if
condition|(
name|column
operator|>=
name|table
operator|->
name|columns
argument_list|()
condition|)
block|{
name|column
operator|=
literal|0
expr_stmt|;
operator|++
name|row
expr_stmt|;
block|}
block|}
while|while
condition|(
name|row
operator|<
name|table
operator|->
name|rows
argument_list|()
operator|&&
name|table
operator|->
name|cellAt
argument_list|(
name|row
argument_list|,
name|column
argument_list|)
operator|.
name|row
argument_list|()
operator|!=
name|row
condition|)
empty_stmt|;
do|return *this;         }
specifier|inline
namespace|bool
name|atEnd
namespace|(
block|)
specifier|const
block|{
return|return
name|table
operator|==
literal|0
operator|||
name|row
operator|>=
name|table
operator|->
name|rows
argument_list|()
return|;
block|}
name|QTextTableCell
name|cell
argument_list|()
specifier|const
block|{
return|return
name|table
operator|->
name|cellAt
argument_list|(
name|row
argument_list|,
name|column
argument_list|)
return|;
block|}
name|QTextTable
operator|*
name|table
block|;
name|int
name|row
block|;
name|int
name|column
block|;     }
decl_stmt|;
end_decl_stmt
begin_macro
name|friend
end_macro
begin_struct_decl
struct_decl|struct
name|Table
struct_decl|;
end_struct_decl
begin_struct
struct|struct
name|Table
block|{
name|Table
argument_list|()
operator|:
name|isTextFrame
argument_list|(
name|false
argument_list|)
operator|,
name|rows
argument_list|(
literal|0
argument_list|)
operator|,
name|columns
argument_list|(
literal|0
argument_list|)
operator|,
name|currentRow
argument_list|(
literal|0
argument_list|)
operator|,
name|lastIndent
argument_list|(
literal|0
argument_list|)
block|{}
name|QPointer
operator|<
name|QTextFrame
operator|>
name|frame
expr_stmt|;
name|bool
name|isTextFrame
decl_stmt|;
name|int
name|rows
decl_stmt|;
name|int
name|columns
decl_stmt|;
name|int
name|currentRow
decl_stmt|;
comment|// ... for buggy html (see html_skipCell testcase)
name|TableCellIterator
name|currentCell
decl_stmt|;
name|int
name|lastIndent
decl_stmt|;
block|}
struct|;
end_struct
begin_expr_stmt
name|QVector
operator|<
name|Table
operator|>
name|tables
expr_stmt|;
end_expr_stmt
begin_struct
struct|struct
name|RowColSpanInfo
block|{
name|int
name|row
decl_stmt|,
name|col
decl_stmt|;
name|int
name|rowSpan
decl_stmt|,
name|colSpan
decl_stmt|;
block|}
struct|;
end_struct
begin_enum
enum|enum
name|WhiteSpace
block|{
name|RemoveWhiteSpace
block|,
name|CollapseWhiteSpace
block|,
name|PreserveWhiteSpace
block|}
enum|;
end_enum
begin_decl_stmt
name|WhiteSpace
name|compressNextWhitespace
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QTextDocument
modifier|*
name|doc
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QTextCursor
name|cursor
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QTextHtmlParserNode
operator|::
name|WhiteSpaceMode
name|wsm
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|ImportMode
name|importMode
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|hasBlock
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|forceBlockMerging
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|blockTagClosed
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|currentNodeIdx
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|const
name|QTextHtmlParserNode
modifier|*
name|currentNode
decl_stmt|;
end_decl_stmt
begin_macro
unit|};
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_TEXTHTMLPARSER
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QTEXTDOCUMENTFRAGMENT_P_H
end_comment
end_unit
