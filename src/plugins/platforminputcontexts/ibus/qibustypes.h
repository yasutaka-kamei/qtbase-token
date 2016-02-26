begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QIBUSTYPES_H
end_ifndef
begin_define
DECL|macro|QIBUSTYPES_H
define|#
directive|define
name|QIBUSTYPES_H
end_define
begin_include
include|#
directive|include
file|<qvector.h>
end_include
begin_include
include|#
directive|include
file|<qevent.h>
end_include
begin_include
include|#
directive|include
file|<QDBusArgument>
end_include
begin_include
include|#
directive|include
file|<QTextCharFormat>
end_include
begin_include
include|#
directive|include
file|<QLoggingCategory>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|Q_DECLARE_LOGGING_CATEGORY
name|Q_DECLARE_LOGGING_CATEGORY
parameter_list|(
name|qtQpaInputMethods
parameter_list|)
function|Q_DECLARE_LOGGING_CATEGORY
parameter_list|(
name|qtQpaInputMethodsSerialize
parameter_list|)
name|class
name|QIBusSerializable
decl_stmt|{ public:     QIBusSerializable(
end_function
begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|void
name|serializeTo
argument_list|(
name|QDBusArgument
operator|&
name|argument
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|deserializeFrom
parameter_list|(
specifier|const
name|QDBusArgument
modifier|&
name|argument
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|QString
name|name
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QHash
operator|<
name|QString
operator|,
name|QDBusArgument
operator|>
name|attachments
expr_stmt|;
end_expr_stmt
begin_decl_stmt
unit|};
name|class
name|QIBusAttribute
range|:
name|private
name|QIBusSerializable
block|{
name|public
operator|:
expr|enum
name|Type
block|{
name|Invalid
operator|=
literal|0
block|,
name|Underline
operator|=
literal|1
block|,
name|Foreground
operator|=
literal|2
block|,
name|Background
operator|=
literal|3
block|,     }
block|;      enum
name|Underline
block|{
name|UnderlineNone
operator|=
literal|0
block|,
name|UnderlineSingle
operator|=
literal|1
block|,
name|UnderlineDouble
operator|=
literal|2
block|,
name|UnderlineLow
operator|=
literal|3
block|,
name|UnderlineError
operator|=
literal|4
block|,     }
block|;
name|QIBusAttribute
argument_list|()
block|;
name|QTextCharFormat
name|format
argument_list|()
specifier|const
block|;
name|void
name|serializeTo
argument_list|(
argument|QDBusArgument&argument
argument_list|)
specifier|const
block|;
name|void
name|deserializeFrom
argument_list|(
specifier|const
name|QDBusArgument
operator|&
name|argument
argument_list|)
block|;
name|Type
name|type
block|;
name|quint32
name|value
block|;
name|quint32
name|start
block|;
name|quint32
name|end
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QIBusAttribute
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|class
name|QIBusAttributeList
range|:
name|private
name|QIBusSerializable
block|{
name|public
operator|:
name|QIBusAttributeList
argument_list|()
block|;
name|QList
operator|<
name|QInputMethodEvent
operator|::
name|Attribute
operator|>
name|imAttributes
argument_list|()
specifier|const
block|;
name|void
name|serializeTo
argument_list|(
argument|QDBusArgument&argument
argument_list|)
specifier|const
block|;
name|void
name|deserializeFrom
argument_list|(
specifier|const
name|QDBusArgument
operator|&
name|argument
argument_list|)
block|;
name|QVector
operator|<
name|QIBusAttribute
operator|>
name|attributes
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QIBusAttributeList
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|class
name|QIBusText
range|:
name|private
name|QIBusSerializable
block|{
name|public
operator|:
name|QIBusText
argument_list|()
block|;
name|void
name|serializeTo
argument_list|(
argument|QDBusArgument&argument
argument_list|)
specifier|const
block|;
name|void
name|deserializeFrom
argument_list|(
specifier|const
name|QDBusArgument
operator|&
name|argument
argument_list|)
block|;
name|QString
name|text
block|;
name|QIBusAttributeList
name|attributes
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QIBusText
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|class
name|QIBusEngineDesc
range|:
name|private
name|QIBusSerializable
block|{
name|public
operator|:
name|QIBusEngineDesc
argument_list|()
block|;
name|void
name|serializeTo
argument_list|(
argument|QDBusArgument&argument
argument_list|)
specifier|const
block|;
name|void
name|deserializeFrom
argument_list|(
specifier|const
name|QDBusArgument
operator|&
name|argument
argument_list|)
block|;
name|QString
name|engine_name
block|;
name|QString
name|longname
block|;
name|QString
name|description
block|;
name|QString
name|language
block|;
name|QString
name|license
block|;
name|QString
name|author
block|;
name|QString
name|icon
block|;
name|QString
name|layout
block|;
name|unsigned
name|int
name|rank
block|;
name|QString
name|hotkeys
block|;
name|QString
name|symbol
block|;
name|QString
name|setup
block|;
name|QString
name|layout_variant
block|;
name|QString
name|layout_option
block|;
name|QString
name|version
block|;
name|QString
name|textdomain
block|;
name|QString
name|iconpropkey
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QIBusEngineDesc
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|QDBusArgument
operator|&
name|operator
operator|<<
operator|(
name|QDBusArgument
operator|&
name|argument
operator|,
specifier|const
name|QIBusAttribute
operator|&
name|attribute
operator|)
block|{
name|attribute
operator|.
name|serializeTo
argument_list|(
name|argument
argument_list|)
block|;
return|return
name|argument
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
specifier|const
name|QDBusArgument
operator|&
name|operator
operator|>>
operator|(
specifier|const
name|QDBusArgument
operator|&
name|argument
operator|,
name|QIBusAttribute
operator|&
name|attribute
operator|)
block|{
name|attribute
operator|.
name|deserializeFrom
argument_list|(
name|argument
argument_list|)
block|;
return|return
name|argument
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|QDBusArgument
operator|&
name|operator
operator|<<
operator|(
name|QDBusArgument
operator|&
name|argument
operator|,
specifier|const
name|QIBusAttributeList
operator|&
name|attributeList
operator|)
block|{
name|attributeList
operator|.
name|serializeTo
argument_list|(
name|argument
argument_list|)
block|;
return|return
name|argument
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
specifier|const
name|QDBusArgument
operator|&
name|operator
operator|>>
operator|(
specifier|const
name|QDBusArgument
operator|&
name|argument
operator|,
name|QIBusAttributeList
operator|&
name|attributeList
operator|)
block|{
name|attributeList
operator|.
name|deserializeFrom
argument_list|(
name|argument
argument_list|)
block|;
return|return
name|argument
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|QDBusArgument
operator|&
name|operator
operator|<<
operator|(
name|QDBusArgument
operator|&
name|argument
operator|,
specifier|const
name|QIBusText
operator|&
name|text
operator|)
block|{
name|text
operator|.
name|serializeTo
argument_list|(
name|argument
argument_list|)
block|;
return|return
name|argument
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
specifier|const
name|QDBusArgument
operator|&
name|operator
operator|>>
operator|(
specifier|const
name|QDBusArgument
operator|&
name|argument
operator|,
name|QIBusText
operator|&
name|text
operator|)
block|{
name|text
operator|.
name|deserializeFrom
argument_list|(
name|argument
argument_list|)
block|;
return|return
name|argument
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|QDBusArgument
operator|&
name|operator
operator|<<
operator|(
name|QDBusArgument
operator|&
name|argument
operator|,
specifier|const
name|QIBusEngineDesc
operator|&
name|desc
operator|)
block|{
name|desc
operator|.
name|serializeTo
argument_list|(
name|argument
argument_list|)
block|;
return|return
name|argument
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
specifier|const
name|QDBusArgument
operator|&
name|operator
operator|>>
operator|(
specifier|const
name|QDBusArgument
operator|&
name|argument
operator|,
name|QIBusEngineDesc
operator|&
name|desc
operator|)
block|{
name|desc
operator|.
name|deserializeFrom
argument_list|(
name|argument
argument_list|)
block|;
return|return
name|argument
return|;
block|}
end_expr_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
name|Q_DECLARE_METATYPE
argument_list|(
name|QIBusAttribute
argument_list|)
name|Q_DECLARE_METATYPE
argument_list|(
name|QIBusAttributeList
argument_list|)
name|Q_DECLARE_METATYPE
argument_list|(
name|QIBusText
argument_list|)
name|Q_DECLARE_METATYPE
argument_list|(
name|QIBusEngineDesc
argument_list|)
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
