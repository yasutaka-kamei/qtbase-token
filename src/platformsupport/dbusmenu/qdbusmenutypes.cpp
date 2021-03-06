begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qdbusmenutypes_p.h"
end_include
begin_include
include|#
directive|include
file|<QDBusConnection>
end_include
begin_include
include|#
directive|include
file|<QDBusMetaType>
end_include
begin_include
include|#
directive|include
file|<QImage>
end_include
begin_include
include|#
directive|include
file|<QIcon>
end_include
begin_include
include|#
directive|include
file|<QImage>
end_include
begin_include
include|#
directive|include
file|<QPixmap>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<QtEndian>
end_include
begin_include
include|#
directive|include
file|<QBuffer>
end_include
begin_include
include|#
directive|include
file|<private/qkeysequence_p.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformmenu.h>
end_include
begin_include
include|#
directive|include
file|"qdbusplatformmenu_p.h"
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|operator <<
specifier|const
name|QDBusArgument
modifier|&
name|operator
name|<<
parameter_list|(
name|QDBusArgument
modifier|&
name|arg
parameter_list|,
specifier|const
name|QDBusMenuItem
modifier|&
name|item
parameter_list|)
block|{
name|arg
operator|.
name|beginStructure
argument_list|()
expr_stmt|;
name|arg
operator|<<
name|item
operator|.
name|m_id
operator|<<
name|item
operator|.
name|m_properties
expr_stmt|;
name|arg
operator|.
name|endStructure
argument_list|()
expr_stmt|;
return|return
name|arg
return|;
block|}
end_function
begin_function
DECL|function|operator >>
specifier|const
name|QDBusArgument
modifier|&
name|operator
name|>>
parameter_list|(
specifier|const
name|QDBusArgument
modifier|&
name|arg
parameter_list|,
name|QDBusMenuItem
modifier|&
name|item
parameter_list|)
block|{
name|arg
operator|.
name|beginStructure
argument_list|()
expr_stmt|;
name|arg
operator|>>
name|item
operator|.
name|m_id
operator|>>
name|item
operator|.
name|m_properties
expr_stmt|;
name|arg
operator|.
name|endStructure
argument_list|()
expr_stmt|;
return|return
name|arg
return|;
block|}
end_function
begin_function
DECL|function|operator <<
specifier|const
name|QDBusArgument
modifier|&
name|operator
name|<<
parameter_list|(
name|QDBusArgument
modifier|&
name|arg
parameter_list|,
specifier|const
name|QDBusMenuItemKeys
modifier|&
name|keys
parameter_list|)
block|{
name|arg
operator|.
name|beginStructure
argument_list|()
expr_stmt|;
name|arg
operator|<<
name|keys
operator|.
name|id
operator|<<
name|keys
operator|.
name|properties
expr_stmt|;
name|arg
operator|.
name|endStructure
argument_list|()
expr_stmt|;
return|return
name|arg
return|;
block|}
end_function
begin_function
DECL|function|operator >>
specifier|const
name|QDBusArgument
modifier|&
name|operator
name|>>
parameter_list|(
specifier|const
name|QDBusArgument
modifier|&
name|arg
parameter_list|,
name|QDBusMenuItemKeys
modifier|&
name|keys
parameter_list|)
block|{
name|arg
operator|.
name|beginStructure
argument_list|()
expr_stmt|;
name|arg
operator|>>
name|keys
operator|.
name|id
operator|>>
name|keys
operator|.
name|properties
expr_stmt|;
name|arg
operator|.
name|endStructure
argument_list|()
expr_stmt|;
return|return
name|arg
return|;
block|}
end_function
begin_function
DECL|function|populate
name|uint
name|QDBusMenuLayoutItem
operator|::
name|populate
parameter_list|(
name|int
name|id
parameter_list|,
name|int
name|depth
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|propertyNames
parameter_list|,
specifier|const
name|QDBusPlatformMenu
modifier|*
name|topLevelMenu
parameter_list|)
block|{
name|qCDebug
argument_list|(
name|qLcMenu
argument_list|)
operator|<<
name|id
operator|<<
literal|"depth"
operator|<<
name|depth
operator|<<
name|propertyNames
expr_stmt|;
name|m_id
operator|=
name|id
expr_stmt|;
if|if
condition|(
name|id
operator|==
literal|0
condition|)
block|{
name|m_properties
operator|.
name|insert
argument_list|(
name|QLatin1String
argument_list|(
literal|"children-display"
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|"submenu"
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|topLevelMenu
condition|)
name|populate
argument_list|(
name|topLevelMenu
argument_list|,
name|depth
argument_list|,
name|propertyNames
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
comment|// revision
block|}
name|QDBusPlatformMenuItem
modifier|*
name|item
init|=
name|QDBusPlatformMenuItem
operator|::
name|byId
argument_list|(
name|id
argument_list|)
decl_stmt|;
if|if
condition|(
name|item
condition|)
block|{
specifier|const
name|QDBusPlatformMenu
modifier|*
name|menu
init|=
cast|static_cast
argument_list|<
specifier|const
name|QDBusPlatformMenu
operator|*
argument_list|>
argument_list|(
name|item
operator|->
name|menu
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|menu
condition|)
block|{
if|if
condition|(
name|depth
operator|!=
literal|0
condition|)
name|populate
argument_list|(
name|menu
argument_list|,
name|depth
argument_list|,
name|propertyNames
argument_list|)
expr_stmt|;
return|return
name|menu
operator|->
name|revision
argument_list|()
return|;
block|}
block|}
return|return
literal|1
return|;
comment|// revision
block|}
end_function
begin_function
DECL|function|populate
name|void
name|QDBusMenuLayoutItem
operator|::
name|populate
parameter_list|(
specifier|const
name|QDBusPlatformMenu
modifier|*
name|menu
parameter_list|,
name|int
name|depth
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|propertyNames
parameter_list|)
block|{
name|Q_FOREACH
argument_list|(
argument|QDBusPlatformMenuItem *item
argument_list|,
argument|menu->items()
argument_list|)
block|{
name|QDBusMenuLayoutItem
name|child
decl_stmt|;
name|child
operator|.
name|populate
argument_list|(
name|item
argument_list|,
name|depth
operator|-
literal|1
argument_list|,
name|propertyNames
argument_list|)
expr_stmt|;
name|m_children
operator|<<
name|child
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|populate
name|void
name|QDBusMenuLayoutItem
operator|::
name|populate
parameter_list|(
specifier|const
name|QDBusPlatformMenuItem
modifier|*
name|item
parameter_list|,
name|int
name|depth
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|propertyNames
parameter_list|)
block|{
name|m_id
operator|=
name|item
operator|->
name|dbusID
argument_list|()
expr_stmt|;
name|QDBusMenuItem
name|proxy
argument_list|(
name|item
argument_list|)
decl_stmt|;
name|m_properties
operator|=
name|proxy
operator|.
name|m_properties
expr_stmt|;
specifier|const
name|QDBusPlatformMenu
modifier|*
name|menu
init|=
cast|static_cast
argument_list|<
specifier|const
name|QDBusPlatformMenu
operator|*
argument_list|>
argument_list|(
name|item
operator|->
name|menu
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|depth
operator|!=
literal|0
operator|&&
name|menu
condition|)
name|populate
argument_list|(
name|menu
argument_list|,
name|depth
argument_list|,
name|propertyNames
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|operator <<
specifier|const
name|QDBusArgument
modifier|&
name|operator
name|<<
parameter_list|(
name|QDBusArgument
modifier|&
name|arg
parameter_list|,
specifier|const
name|QDBusMenuLayoutItem
modifier|&
name|item
parameter_list|)
block|{
name|arg
operator|.
name|beginStructure
argument_list|()
expr_stmt|;
name|arg
operator|<<
name|item
operator|.
name|m_id
operator|<<
name|item
operator|.
name|m_properties
expr_stmt|;
name|arg
operator|.
name|beginArray
argument_list|(
name|qMetaTypeId
argument_list|<
name|QDBusVariant
argument_list|>
argument_list|()
argument_list|)
expr_stmt|;
foreach|foreach
control|(
specifier|const
name|QDBusMenuLayoutItem
modifier|&
name|child
decl|,
name|item
operator|.
name|m_children
control|)
name|arg
operator|<<
name|QDBusVariant
argument_list|(
name|QVariant
operator|::
name|fromValue
argument_list|<
name|QDBusMenuLayoutItem
argument_list|>
argument_list|(
name|child
argument_list|)
argument_list|)
expr_stmt|;
name|arg
operator|.
name|endArray
argument_list|()
expr_stmt|;
name|arg
operator|.
name|endStructure
argument_list|()
expr_stmt|;
return|return
name|arg
return|;
block|}
end_function
begin_function
DECL|function|operator >>
specifier|const
name|QDBusArgument
modifier|&
name|operator
name|>>
parameter_list|(
specifier|const
name|QDBusArgument
modifier|&
name|arg
parameter_list|,
name|QDBusMenuLayoutItem
modifier|&
name|item
parameter_list|)
block|{
name|arg
operator|.
name|beginStructure
argument_list|()
expr_stmt|;
name|arg
operator|>>
name|item
operator|.
name|m_id
operator|>>
name|item
operator|.
name|m_properties
expr_stmt|;
name|arg
operator|.
name|beginArray
argument_list|()
expr_stmt|;
while|while
condition|(
operator|!
name|arg
operator|.
name|atEnd
argument_list|()
condition|)
block|{
name|QDBusVariant
name|dbusVariant
decl_stmt|;
name|arg
operator|>>
name|dbusVariant
expr_stmt|;
name|QDBusArgument
name|childArgument
init|=
name|dbusVariant
operator|.
name|variant
argument_list|()
operator|.
name|value
argument_list|<
name|QDBusArgument
argument_list|>
argument_list|()
decl_stmt|;
name|QDBusMenuLayoutItem
name|child
decl_stmt|;
name|childArgument
operator|>>
name|child
expr_stmt|;
name|item
operator|.
name|m_children
operator|.
name|append
argument_list|(
name|child
argument_list|)
expr_stmt|;
block|}
name|arg
operator|.
name|endArray
argument_list|()
expr_stmt|;
name|arg
operator|.
name|endStructure
argument_list|()
expr_stmt|;
return|return
name|arg
return|;
block|}
end_function
begin_function
DECL|function|registerDBusTypes
name|void
name|QDBusMenuItem
operator|::
name|registerDBusTypes
parameter_list|()
block|{
name|qDBusRegisterMetaType
argument_list|<
name|QDBusMenuItem
argument_list|>
argument_list|()
expr_stmt|;
name|qDBusRegisterMetaType
argument_list|<
name|QDBusMenuItemList
argument_list|>
argument_list|()
expr_stmt|;
name|qDBusRegisterMetaType
argument_list|<
name|QDBusMenuItemKeys
argument_list|>
argument_list|()
expr_stmt|;
name|qDBusRegisterMetaType
argument_list|<
name|QDBusMenuItemKeysList
argument_list|>
argument_list|()
expr_stmt|;
name|qDBusRegisterMetaType
argument_list|<
name|QDBusMenuLayoutItem
argument_list|>
argument_list|()
expr_stmt|;
name|qDBusRegisterMetaType
argument_list|<
name|QDBusMenuLayoutItemList
argument_list|>
argument_list|()
expr_stmt|;
name|qDBusRegisterMetaType
argument_list|<
name|QDBusMenuEvent
argument_list|>
argument_list|()
expr_stmt|;
name|qDBusRegisterMetaType
argument_list|<
name|QDBusMenuEventList
argument_list|>
argument_list|()
expr_stmt|;
name|qDBusRegisterMetaType
argument_list|<
name|QDBusMenuShortcut
argument_list|>
argument_list|()
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|QDBusMenuItem
name|QDBusMenuItem
operator|::
name|QDBusMenuItem
parameter_list|(
specifier|const
name|QDBusPlatformMenuItem
modifier|*
name|item
parameter_list|)
member_init_list|:
name|m_id
argument_list|(
name|item
operator|->
name|dbusID
argument_list|()
argument_list|)
block|{
if|if
condition|(
name|item
operator|->
name|isSeparator
argument_list|()
condition|)
block|{
name|m_properties
operator|.
name|insert
argument_list|(
name|QLatin1String
argument_list|(
literal|"type"
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|"separator"
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|m_properties
operator|.
name|insert
argument_list|(
name|QLatin1String
argument_list|(
literal|"label"
argument_list|)
argument_list|,
name|convertMnemonic
argument_list|(
name|item
operator|->
name|text
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|item
operator|->
name|menu
argument_list|()
condition|)
name|m_properties
operator|.
name|insert
argument_list|(
name|QLatin1String
argument_list|(
literal|"children-display"
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|"submenu"
argument_list|)
argument_list|)
expr_stmt|;
name|m_properties
operator|.
name|insert
argument_list|(
name|QLatin1String
argument_list|(
literal|"enabled"
argument_list|)
argument_list|,
name|item
operator|->
name|isEnabled
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|item
operator|->
name|isCheckable
argument_list|()
condition|)
block|{
name|QString
name|toggleType
init|=
name|item
operator|->
name|hasExclusiveGroup
argument_list|()
condition|?
name|QLatin1String
argument_list|(
literal|"radio"
argument_list|)
else|:
name|QLatin1String
argument_list|(
literal|"checkmark"
argument_list|)
decl_stmt|;
name|m_properties
operator|.
name|insert
argument_list|(
name|QLatin1String
argument_list|(
literal|"toggle-type"
argument_list|)
argument_list|,
name|toggleType
argument_list|)
expr_stmt|;
name|m_properties
operator|.
name|insert
argument_list|(
name|QLatin1String
argument_list|(
literal|"toggle-state"
argument_list|)
argument_list|,
name|item
operator|->
name|isChecked
argument_list|()
condition|?
literal|1
else|:
literal|0
argument_list|)
expr_stmt|;
block|}
specifier|const
name|QKeySequence
modifier|&
name|scut
init|=
name|item
operator|->
name|shortcut
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|scut
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QDBusMenuShortcut
name|shortcut
init|=
name|convertKeySequence
argument_list|(
name|scut
argument_list|)
decl_stmt|;
name|m_properties
operator|.
name|insert
argument_list|(
name|QLatin1String
argument_list|(
literal|"shortcut"
argument_list|)
argument_list|,
name|QVariant
operator|::
name|fromValue
argument_list|(
name|shortcut
argument_list|)
argument_list|)
expr_stmt|;
block|}
specifier|const
name|QIcon
modifier|&
name|icon
init|=
name|item
operator|->
name|icon
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|icon
operator|.
name|name
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|m_properties
operator|.
name|insert
argument_list|(
name|QLatin1String
argument_list|(
literal|"icon-name"
argument_list|)
argument_list|,
name|icon
operator|.
name|name
argument_list|()
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|!
name|icon
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|QBuffer
name|buf
decl_stmt|;
name|icon
operator|.
name|pixmap
argument_list|(
literal|16
argument_list|)
operator|.
name|save
argument_list|(
operator|&
name|buf
argument_list|,
literal|"PNG"
argument_list|)
expr_stmt|;
name|m_properties
operator|.
name|insert
argument_list|(
name|QLatin1String
argument_list|(
literal|"icon-data"
argument_list|)
argument_list|,
name|buf
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
name|m_properties
operator|.
name|insert
argument_list|(
name|QLatin1String
argument_list|(
literal|"visible"
argument_list|)
argument_list|,
name|item
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|items
name|QDBusMenuItemList
name|QDBusMenuItem
operator|::
name|items
parameter_list|(
specifier|const
name|QList
argument_list|<
name|int
argument_list|>
modifier|&
name|ids
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|propertyNames
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
argument|propertyNames
argument_list|)
name|QDBusMenuItemList
name|ret
decl_stmt|;
name|QList
argument_list|<
specifier|const
name|QDBusPlatformMenuItem
modifier|*
argument_list|>
name|items
init|=
name|QDBusPlatformMenuItem
operator|::
name|byIds
argument_list|(
name|ids
argument_list|)
decl_stmt|;
name|ret
operator|.
name|reserve
argument_list|(
name|items
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|Q_FOREACH
argument_list|(
argument|const QDBusPlatformMenuItem *item
argument_list|,
argument|items
argument_list|)
name|ret
operator|<<
name|QDBusMenuItem
argument_list|(
name|item
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function
begin_function
DECL|function|convertMnemonic
name|QString
name|QDBusMenuItem
operator|::
name|convertMnemonic
parameter_list|(
specifier|const
name|QString
modifier|&
name|label
parameter_list|)
block|{
comment|// convert only the first occurrence of ampersand which is not at the end
comment|// dbusmenu uses underscore instead of ampersand
name|int
name|idx
init|=
name|label
operator|.
name|indexOf
argument_list|(
name|QLatin1Char
argument_list|(
literal|'&'
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|idx
operator|<
literal|0
operator|||
name|idx
operator|==
name|label
operator|.
name|length
argument_list|()
operator|-
literal|1
condition|)
return|return
name|label
return|;
name|QString
name|ret
argument_list|(
name|label
argument_list|)
decl_stmt|;
name|ret
index|[
name|idx
index|]
operator|=
name|QLatin1Char
argument_list|(
literal|'_'
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function
begin_function
DECL|function|convertKeySequence
name|QDBusMenuShortcut
name|QDBusMenuItem
operator|::
name|convertKeySequence
parameter_list|(
specifier|const
name|QKeySequence
modifier|&
name|sequence
parameter_list|)
block|{
name|QDBusMenuShortcut
name|shortcut
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|sequence
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QStringList
name|tokens
decl_stmt|;
name|int
name|key
init|=
name|sequence
index|[
name|i
index|]
decl_stmt|;
if|if
condition|(
name|key
operator|&
name|Qt
operator|::
name|MetaModifier
condition|)
name|tokens
operator|<<
name|QStringLiteral
argument_list|(
literal|"Super"
argument_list|)
expr_stmt|;
if|if
condition|(
name|key
operator|&
name|Qt
operator|::
name|ControlModifier
condition|)
name|tokens
operator|<<
name|QStringLiteral
argument_list|(
literal|"Control"
argument_list|)
expr_stmt|;
if|if
condition|(
name|key
operator|&
name|Qt
operator|::
name|AltModifier
condition|)
name|tokens
operator|<<
name|QStringLiteral
argument_list|(
literal|"Alt"
argument_list|)
expr_stmt|;
if|if
condition|(
name|key
operator|&
name|Qt
operator|::
name|ShiftModifier
condition|)
name|tokens
operator|<<
name|QStringLiteral
argument_list|(
literal|"Shift"
argument_list|)
expr_stmt|;
if|if
condition|(
name|key
operator|&
name|Qt
operator|::
name|KeypadModifier
condition|)
name|tokens
operator|<<
name|QStringLiteral
argument_list|(
literal|"Num"
argument_list|)
expr_stmt|;
name|QString
name|keyName
init|=
name|QKeySequencePrivate
operator|::
name|keyName
argument_list|(
name|key
argument_list|,
name|QKeySequence
operator|::
name|PortableText
argument_list|)
decl_stmt|;
if|if
condition|(
name|keyName
operator|==
name|QLatin1String
argument_list|(
literal|"+"
argument_list|)
condition|)
name|tokens
operator|<<
name|QStringLiteral
argument_list|(
literal|"plus"
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|keyName
operator|==
name|QLatin1String
argument_list|(
literal|"-"
argument_list|)
condition|)
name|tokens
operator|<<
name|QStringLiteral
argument_list|(
literal|"minus"
argument_list|)
expr_stmt|;
else|else
name|tokens
operator|<<
name|keyName
expr_stmt|;
name|shortcut
operator|<<
name|tokens
expr_stmt|;
block|}
return|return
name|shortcut
return|;
block|}
end_function
begin_function
DECL|function|operator <<
specifier|const
name|QDBusArgument
modifier|&
name|operator
name|<<
parameter_list|(
name|QDBusArgument
modifier|&
name|arg
parameter_list|,
specifier|const
name|QDBusMenuEvent
modifier|&
name|ev
parameter_list|)
block|{
name|arg
operator|.
name|beginStructure
argument_list|()
expr_stmt|;
name|arg
operator|<<
name|ev
operator|.
name|m_id
operator|<<
name|ev
operator|.
name|m_eventId
operator|<<
name|ev
operator|.
name|m_data
operator|<<
name|ev
operator|.
name|m_timestamp
expr_stmt|;
name|arg
operator|.
name|endStructure
argument_list|()
expr_stmt|;
return|return
name|arg
return|;
block|}
end_function
begin_function
DECL|function|operator >>
specifier|const
name|QDBusArgument
modifier|&
name|operator
name|>>
parameter_list|(
specifier|const
name|QDBusArgument
modifier|&
name|arg
parameter_list|,
name|QDBusMenuEvent
modifier|&
name|ev
parameter_list|)
block|{
name|arg
operator|.
name|beginStructure
argument_list|()
expr_stmt|;
name|arg
operator|>>
name|ev
operator|.
name|m_id
operator|>>
name|ev
operator|.
name|m_eventId
operator|>>
name|ev
operator|.
name|m_data
operator|>>
name|ev
operator|.
name|m_timestamp
expr_stmt|;
name|arg
operator|.
name|endStructure
argument_list|()
expr_stmt|;
return|return
name|arg
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_function
DECL|function|operator <<
name|QDebug
name|operator
name|<<
parameter_list|(
name|QDebug
name|d
parameter_list|,
specifier|const
name|QDBusMenuItem
modifier|&
name|item
parameter_list|)
block|{
name|QDebugStateSaver
name|saver
argument_list|(
name|d
argument_list|)
decl_stmt|;
name|d
operator|.
name|nospace
argument_list|()
expr_stmt|;
name|d
operator|<<
literal|"QDBusMenuItem(id="
operator|<<
name|item
operator|.
name|m_id
operator|<<
literal|", properties="
operator|<<
name|item
operator|.
name|m_properties
operator|<<
literal|')'
expr_stmt|;
return|return
name|d
return|;
block|}
end_function
begin_function
DECL|function|operator <<
name|QDebug
name|operator
name|<<
parameter_list|(
name|QDebug
name|d
parameter_list|,
specifier|const
name|QDBusMenuLayoutItem
modifier|&
name|item
parameter_list|)
block|{
name|QDebugStateSaver
name|saver
argument_list|(
name|d
argument_list|)
decl_stmt|;
name|d
operator|.
name|nospace
argument_list|()
expr_stmt|;
name|d
operator|<<
literal|"QDBusMenuLayoutItem(id="
operator|<<
name|item
operator|.
name|m_id
operator|<<
literal|", properties="
operator|<<
name|item
operator|.
name|m_properties
operator|<<
literal|", "
operator|<<
name|item
operator|.
name|m_children
operator|.
name|count
argument_list|()
operator|<<
literal|" children)"
expr_stmt|;
return|return
name|d
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
