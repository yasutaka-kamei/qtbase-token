begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|ATOM_H
end_ifndef
begin_define
DECL|macro|ATOM_H
define|#
directive|define
name|ATOM_H
end_define
begin_include
include|#
directive|include
file|<qstringlist.h>
end_include
begin_include
include|#
directive|include
file|"node.h"
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|Tree
name|class
name|Tree
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|LinkAtom
name|class
name|LinkAtom
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Atom
block|{
name|public
label|:
enum|enum
name|Type
block|{
name|AbstractLeft
block|,
name|AbstractRight
block|,
name|AnnotatedList
block|,
name|AutoLink
block|,
name|BaseName
block|,
name|BR
block|,
name|BriefLeft
block|,
name|BriefRight
block|,
name|C
block|,
name|CaptionLeft
block|,
name|CaptionRight
block|,
comment|// 10
name|Code
block|,
name|CodeBad
block|,
name|CodeNew
block|,
name|CodeOld
block|,
name|CodeQuoteArgument
block|,
name|CodeQuoteCommand
block|,
name|DivLeft
block|,
name|DivRight
block|,
name|EndQmlText
block|,
name|FootnoteLeft
block|,
comment|// 20
name|FootnoteRight
block|,
name|FormatElse
block|,
name|FormatEndif
block|,
name|FormatIf
block|,
name|FormattingLeft
block|,
name|FormattingRight
block|,
name|GeneratedList
block|,
name|GuidLink
block|,
name|HR
block|,
name|Image
block|,
comment|// 30
name|ImageText
block|,
name|ImportantLeft
block|,
name|ImportantRight
block|,
name|InlineImage
block|,
name|JavaScript
block|,
name|EndJavaScript
block|,
name|LegaleseLeft
block|,
name|LegaleseRight
block|,
name|LineBreak
block|,
name|Link
block|,
comment|// 40
name|LinkNode
block|,
name|ListLeft
block|,
name|ListItemNumber
block|,
name|ListTagLeft
block|,
name|ListTagRight
block|,
name|ListItemLeft
block|,
name|ListItemRight
block|,
name|ListRight
block|,
name|Nop
block|,
name|NoteLeft
block|,
comment|// 50
name|NoteRight
block|,
name|ParaLeft
block|,
name|ParaRight
block|,
name|Qml
block|,
name|QmlText
block|,
name|QuotationLeft
block|,
name|QuotationRight
block|,
name|RawString
block|,
name|SectionLeft
block|,
name|SectionRight
block|,
comment|// 60
name|SectionHeadingLeft
block|,
name|SectionHeadingRight
block|,
name|SidebarLeft
block|,
name|SidebarRight
block|,
name|SinceList
block|,
name|SnippetCommand
block|,
name|SnippetIdentifier
block|,
name|SnippetLocation
block|,
name|String
block|,
name|TableLeft
block|,
comment|// 70
name|TableRight
block|,
name|TableHeaderLeft
block|,
name|TableHeaderRight
block|,
name|TableRowLeft
block|,
name|TableRowRight
block|,
name|TableItemLeft
block|,
name|TableItemRight
block|,
name|TableOfContents
block|,
name|Target
block|,
name|UnhandledFormat
block|,
comment|// 80
name|UnknownCommand
block|,
name|Last
init|=
name|UnknownCommand
block|}
enum|;
name|friend
name|class
name|LinkAtom
decl_stmt|;
name|Atom
argument_list|(
specifier|const
name|QString
operator|&
name|string
argument_list|)
operator|:
name|next_
argument_list|(
literal|0
argument_list|)
operator|,
name|type_
argument_list|(
argument|Link
argument_list|)
block|{
name|strs
operator|<<
name|string
block|;     }
name|Atom
argument_list|(
argument|Type type
argument_list|,
argument|const QString& string =
literal|""
argument_list|)
operator|:
name|next_
argument_list|(
literal|0
argument_list|)
operator|,
name|type_
argument_list|(
argument|type
argument_list|)
block|{
name|strs
operator|<<
name|string
block|;     }
name|Atom
argument_list|(
argument|Type type
argument_list|,
argument|const QString& p1
argument_list|,
argument|const QString& p2
argument_list|)
operator|:
name|next_
argument_list|(
literal|0
argument_list|)
operator|,
name|type_
argument_list|(
argument|type
argument_list|)
block|{
name|strs
operator|<<
name|p1
block|;
if|if
condition|(
operator|!
name|p2
operator|.
name|isEmpty
argument_list|()
condition|)
name|strs
operator|<<
name|p2
expr_stmt|;
block|}
name|Atom
argument_list|(
argument|Atom* previous
argument_list|,
argument|Type type
argument_list|,
argument|const QString& string =
literal|""
argument_list|)
block|:
name|next_
argument_list|(
name|previous
operator|->
name|next_
argument_list|)
operator|,
name|type_
argument_list|(
argument|type
argument_list|)
block|{
name|strs
operator|<<
name|string
block|;
name|previous
operator|->
name|next_
operator|=
name|this
block|;     }
name|Atom
argument_list|(
argument|Atom* previous
argument_list|,
argument|Type type
argument_list|,
argument|const QString& p1
argument_list|,
argument|const QString& p2
argument_list|)
operator|:
name|next_
argument_list|(
name|previous
operator|->
name|next_
argument_list|)
operator|,
name|type_
argument_list|(
argument|type
argument_list|)
block|{
name|strs
operator|<<
name|p1
block|;
if|if
condition|(
operator|!
name|p2
operator|.
name|isEmpty
argument_list|()
condition|)
name|strs
operator|<<
name|p2
expr_stmt|;
name|previous
operator|->
name|next_
operator|=
name|this
expr_stmt|;
block|}
end_decl_stmt
begin_expr_stmt
name|virtual
operator|~
name|Atom
argument_list|()
block|{ }
name|void
name|appendChar
argument_list|(
argument|QChar ch
argument_list|)
block|{
name|strs
index|[
literal|0
index|]
operator|+=
name|ch
block|; }
name|void
name|appendString
argument_list|(
argument|const QString& string
argument_list|)
block|{
name|strs
index|[
literal|0
index|]
operator|+=
name|string
block|; }
name|void
name|chopString
argument_list|()
block|{
name|strs
index|[
literal|0
index|]
operator|.
name|chop
argument_list|(
literal|1
argument_list|)
block|; }
name|void
name|setString
argument_list|(
argument|const QString& string
argument_list|)
block|{
name|strs
index|[
literal|0
index|]
operator|=
name|string
block|; }
name|Atom
operator|*
name|next
argument_list|()
block|{
return|return
name|next_
return|;
block|}
end_expr_stmt
begin_function
name|void
name|setNext
parameter_list|(
name|Atom
modifier|*
name|newNext
parameter_list|)
block|{
name|next_
operator|=
name|newNext
expr_stmt|;
block|}
end_function
begin_expr_stmt
specifier|const
name|Atom
operator|*
name|next
argument_list|()
specifier|const
block|{
return|return
name|next_
return|;
block|}
end_expr_stmt
begin_decl_stmt
specifier|const
name|Atom
modifier|*
name|next
argument_list|(
name|Type
name|t
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|const
name|Atom
modifier|*
name|next
argument_list|(
name|Type
name|t
argument_list|,
specifier|const
name|QString
operator|&
name|s
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|Type
name|type
argument_list|()
specifier|const
block|{
return|return
name|type_
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|QString
name|typeString
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
specifier|const
name|QString
operator|&
name|string
argument_list|()
specifier|const
block|{
return|return
name|strs
index|[
literal|0
index|]
return|;
block|}
end_expr_stmt
begin_decl_stmt
specifier|const
name|QString
modifier|&
name|string
argument_list|(
name|int
name|i
argument_list|)
decl|const
block|{
return|return
name|strs
index|[
name|i
index|]
return|;
block|}
end_decl_stmt
begin_expr_stmt
name|int
name|count
argument_list|()
specifier|const
block|{
return|return
name|strs
operator|.
name|size
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
specifier|const
name|QStringList
operator|&
name|strings
argument_list|()
specifier|const
block|{
return|return
name|strs
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|virtual
name|bool
name|isLinkAtom
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|virtual
name|Node
operator|::
name|Genus
name|genus
argument_list|()
specifier|const
block|{
return|return
name|Node
operator|::
name|DontCare
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|virtual
name|bool
name|specifiesDomain
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|virtual
name|Tree
operator|*
name|domain
argument_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|virtual
name|Node
operator|::
name|Type
name|goal
argument_list|()
specifier|const
block|{
return|return
name|Node
operator|::
name|NoType
return|;
block|}
end_expr_stmt
begin_label
name|protected
label|:
end_label
begin_decl_stmt
name|Atom
modifier|*
name|next_
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|Type
name|type_
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QStringList
name|strs
decl_stmt|;
end_decl_stmt
begin_decl_stmt
unit|};
name|class
name|LinkAtom
range|:
name|public
name|Atom
block|{
name|public
operator|:
name|LinkAtom
argument_list|(
specifier|const
name|QString
operator|&
name|p1
argument_list|,
specifier|const
name|QString
operator|&
name|p2
argument_list|)
block|;
name|LinkAtom
argument_list|(
specifier|const
name|LinkAtom
operator|&
name|t
argument_list|)
block|;
name|LinkAtom
argument_list|(
name|Atom
operator|*
name|previous
argument_list|,
specifier|const
name|LinkAtom
operator|&
name|t
argument_list|)
block|;
name|virtual
operator|~
name|LinkAtom
argument_list|()
block|{ }
name|virtual
name|bool
name|isLinkAtom
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
name|virtual
name|Node
operator|::
name|Genus
name|genus
argument_list|()
specifier|const
block|{
return|return
name|genus_
return|;
block|}
name|virtual
name|bool
name|specifiesDomain
argument_list|()
specifier|const
block|{
return|return
operator|(
name|domain_
operator|!=
literal|0
operator|)
return|;
block|}
name|virtual
name|Tree
operator|*
name|domain
argument_list|()
specifier|const
block|{
return|return
name|domain_
return|;
block|}
name|virtual
name|Node
operator|::
name|Type
name|goal
argument_list|()
specifier|const
block|{
return|return
name|goal_
return|;
block|}
name|protected
operator|:
name|Node
operator|::
name|Genus
name|genus_
block|;
name|Node
operator|::
name|Type
name|goal_
block|;
name|Tree
operator|*
name|domain_
block|; }
decl_stmt|;
end_decl_stmt
begin_define
DECL|macro|ATOM_FORMATTING_BOLD
define|#
directive|define
name|ATOM_FORMATTING_BOLD
value|"bold"
end_define
begin_define
DECL|macro|ATOM_FORMATTING_INDEX
define|#
directive|define
name|ATOM_FORMATTING_INDEX
value|"index"
end_define
begin_define
DECL|macro|ATOM_FORMATTING_ITALIC
define|#
directive|define
name|ATOM_FORMATTING_ITALIC
value|"italic"
end_define
begin_define
DECL|macro|ATOM_FORMATTING_LINK
define|#
directive|define
name|ATOM_FORMATTING_LINK
value|"link"
end_define
begin_define
DECL|macro|ATOM_FORMATTING_PARAMETER
define|#
directive|define
name|ATOM_FORMATTING_PARAMETER
value|"parameter"
end_define
begin_define
DECL|macro|ATOM_FORMATTING_SPAN
define|#
directive|define
name|ATOM_FORMATTING_SPAN
value|"span "
end_define
begin_define
DECL|macro|ATOM_FORMATTING_SUBSCRIPT
define|#
directive|define
name|ATOM_FORMATTING_SUBSCRIPT
value|"subscript"
end_define
begin_define
DECL|macro|ATOM_FORMATTING_SUPERSCRIPT
define|#
directive|define
name|ATOM_FORMATTING_SUPERSCRIPT
value|"superscript"
end_define
begin_define
DECL|macro|ATOM_FORMATTING_TELETYPE
define|#
directive|define
name|ATOM_FORMATTING_TELETYPE
value|"teletype"
end_define
begin_define
DECL|macro|ATOM_FORMATTING_UICONTROL
define|#
directive|define
name|ATOM_FORMATTING_UICONTROL
value|"uicontrol"
end_define
begin_define
DECL|macro|ATOM_FORMATTING_UNDERLINE
define|#
directive|define
name|ATOM_FORMATTING_UNDERLINE
value|"underline"
end_define
begin_define
DECL|macro|ATOM_LIST_BULLET
define|#
directive|define
name|ATOM_LIST_BULLET
value|"bullet"
end_define
begin_define
DECL|macro|ATOM_LIST_TAG
define|#
directive|define
name|ATOM_LIST_TAG
value|"tag"
end_define
begin_define
DECL|macro|ATOM_LIST_VALUE
define|#
directive|define
name|ATOM_LIST_VALUE
value|"value"
end_define
begin_define
DECL|macro|ATOM_LIST_LOWERALPHA
define|#
directive|define
name|ATOM_LIST_LOWERALPHA
value|"loweralpha"
end_define
begin_define
DECL|macro|ATOM_LIST_LOWERROMAN
define|#
directive|define
name|ATOM_LIST_LOWERROMAN
value|"lowerroman"
end_define
begin_define
DECL|macro|ATOM_LIST_NUMERIC
define|#
directive|define
name|ATOM_LIST_NUMERIC
value|"numeric"
end_define
begin_define
DECL|macro|ATOM_LIST_UPPERALPHA
define|#
directive|define
name|ATOM_LIST_UPPERALPHA
value|"upperalpha"
end_define
begin_define
DECL|macro|ATOM_LIST_UPPERROMAN
define|#
directive|define
name|ATOM_LIST_UPPERROMAN
value|"upperroman"
end_define
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
