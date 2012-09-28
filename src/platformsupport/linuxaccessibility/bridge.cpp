begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"bridge_p.h"
end_include
begin_include
include|#
directive|include
file|<atspi/atspi-constants.h>
end_include
begin_include
include|#
directive|include
file|<qstring.h>
end_include
begin_include
include|#
directive|include
file|"atspiadaptor_p.h"
end_include
begin_include
include|#
directive|include
file|"cache_p.h"
end_include
begin_include
include|#
directive|include
file|"constant_mappings_p.h"
end_include
begin_include
include|#
directive|include
file|"dbusconnection_p.h"
end_include
begin_include
include|#
directive|include
file|"struct_marshallers_p.h"
end_include
begin_include
include|#
directive|include
file|"deviceeventcontroller_adaptor.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QSpiAccessibleBridge     \internal */
end_comment
begin_constructor
DECL|function|QSpiAccessibleBridge
name|QSpiAccessibleBridge
operator|::
name|QSpiAccessibleBridge
parameter_list|()
member_init_list|:
name|cache
argument_list|(
literal|0
argument_list|)
block|{
name|dbusConnection
operator|=
operator|new
name|DBusConnection
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|dBusConnection
argument_list|()
operator|.
name|isConnected
argument_list|()
condition|)
name|qWarning
argument_list|()
operator|<<
literal|"Could not connect to dbus."
expr_stmt|;
name|qSpiInitializeStructTypes
argument_list|()
expr_stmt|;
name|initializeConstantMappings
argument_list|()
expr_stmt|;
comment|/* Create the cache of accessible objects */
name|cache
operator|=
operator|new
name|QSpiDBusCache
argument_list|(
name|dBusConnection
argument_list|()
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|dec
operator|=
operator|new
name|DeviceEventControllerAdaptor
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|dBusConnection
argument_list|()
operator|.
name|registerObject
argument_list|(
name|QLatin1String
argument_list|(
name|ATSPI_DBUS_PATH_DEC
argument_list|)
argument_list|,
name|this
argument_list|,
name|QDBusConnection
operator|::
name|ExportAdaptors
argument_list|)
expr_stmt|;
name|dbusAdaptor
operator|=
operator|new
name|AtSpiAdaptor
argument_list|(
name|dbusConnection
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|dBusConnection
argument_list|()
operator|.
name|registerVirtualObject
argument_list|(
name|QLatin1String
argument_list|(
name|QSPI_OBJECT_PATH_ACCESSIBLE
argument_list|)
argument_list|,
name|dbusAdaptor
argument_list|,
name|QDBusConnection
operator|::
name|SubPath
argument_list|)
expr_stmt|;
name|dbusAdaptor
operator|->
name|registerApplication
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QSpiAccessibleBridge
name|QSpiAccessibleBridge
operator|::
name|~
name|QSpiAccessibleBridge
parameter_list|()
block|{
operator|delete
name|dbusConnection
expr_stmt|;
block|}
end_destructor
begin_comment
comment|// Qt currently doesn't delete plugins.
end_comment
begin_function
DECL|function|dBusConnection
name|QDBusConnection
name|QSpiAccessibleBridge
operator|::
name|dBusConnection
parameter_list|()
specifier|const
block|{
return|return
name|dbusConnection
operator|->
name|connection
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|setRootObject
name|void
name|QSpiAccessibleBridge
operator|::
name|setRootObject
parameter_list|(
name|QObject
modifier|*
name|obj
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|obj
argument_list|)
expr_stmt|;
name|dbusAdaptor
operator|->
name|setInitialized
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|notifyAccessibilityUpdate
name|void
name|QSpiAccessibleBridge
operator|::
name|notifyAccessibilityUpdate
parameter_list|(
name|QAccessibleEvent
modifier|*
name|event
parameter_list|)
block|{
name|dbusAdaptor
operator|->
name|notify
argument_list|(
name|event
argument_list|)
expr_stmt|;
block|}
end_function
begin_struct
DECL|struct|RoleMapping
struct|struct
name|RoleMapping
block|{
DECL|member|role
name|QAccessible
operator|::
name|Role
name|role
decl_stmt|;
DECL|member|spiRole
name|AtspiRole
name|spiRole
decl_stmt|;
DECL|member|name
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
DECL|member|localizedName
specifier|const
name|char
modifier|*
name|localizedName
decl_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
DECL|variable|map
specifier|static
name|RoleMapping
name|map
index|[]
init|=
block|{
block|{
name|QAccessible
operator|::
name|NoRole
block|,
name|ATSPI_ROLE_INVALID
block|,
literal|"invalid"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"invalid role"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|TitleBar
block|,
name|ATSPI_ROLE_TEXT
block|,
literal|"text"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"title bar"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|MenuBar
block|,
name|ATSPI_ROLE_MENU_BAR
block|,
literal|"menu bar"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"menu bar"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|ScrollBar
block|,
name|ATSPI_ROLE_SCROLL_BAR
block|,
literal|"scroll bar"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"scroll bar"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|Grip
block|,
name|ATSPI_ROLE_UNKNOWN
block|,
literal|"unknown"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"grip"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|Sound
block|,
name|ATSPI_ROLE_UNKNOWN
block|,
literal|"unknown"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"sound"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|Cursor
block|,
name|ATSPI_ROLE_ARROW
block|,
literal|"arrow"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"cursor"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|Caret
block|,
name|ATSPI_ROLE_UNKNOWN
block|,
literal|"unknown"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"caret"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|AlertMessage
block|,
name|ATSPI_ROLE_ALERT
block|,
literal|"alert"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"alert message"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|Window
block|,
name|ATSPI_ROLE_WINDOW
block|,
literal|"window"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"window"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|Client
block|,
name|ATSPI_ROLE_FILLER
block|,
literal|"filler"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"filler"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|PopupMenu
block|,
name|ATSPI_ROLE_POPUP_MENU
block|,
literal|"popup menu"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"popup menu"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|MenuItem
block|,
name|ATSPI_ROLE_MENU_ITEM
block|,
literal|"menu item"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"menu item"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|ToolTip
block|,
name|ATSPI_ROLE_TOOL_TIP
block|,
literal|"tool tip"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"tool tip"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|Application
block|,
name|ATSPI_ROLE_APPLICATION
block|,
literal|"application"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"application"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|Document
block|,
name|ATSPI_ROLE_DOCUMENT_FRAME
block|,
literal|"document frame"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"document"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|Pane
block|,
name|ATSPI_ROLE_PANEL
block|,
literal|"panel"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"pane"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|Chart
block|,
name|ATSPI_ROLE_CHART
block|,
literal|"chart"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"chart"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|Dialog
block|,
name|ATSPI_ROLE_DIALOG
block|,
literal|"dialog"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"dialog"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|Border
block|,
name|ATSPI_ROLE_FRAME
block|,
literal|"frame"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"border"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|Grouping
block|,
name|ATSPI_ROLE_PANEL
block|,
literal|"panel"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"grouping"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|Separator
block|,
name|ATSPI_ROLE_SEPARATOR
block|,
literal|"separator"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"separator"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|ToolBar
block|,
name|ATSPI_ROLE_TOOL_BAR
block|,
literal|"tool bar"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"tool bar"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|StatusBar
block|,
name|ATSPI_ROLE_STATUS_BAR
block|,
literal|"statusbar"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"status bar"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|Table
block|,
name|ATSPI_ROLE_TABLE
block|,
literal|"table"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"table"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|ColumnHeader
block|,
name|ATSPI_ROLE_TABLE_COLUMN_HEADER
block|,
literal|"column header"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"column header"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|RowHeader
block|,
name|ATSPI_ROLE_TABLE_ROW_HEADER
block|,
literal|"row header"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"row header"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|Column
block|,
name|ATSPI_ROLE_TABLE_CELL
block|,
literal|"table cell"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"column"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|Row
block|,
name|ATSPI_ROLE_TABLE_CELL
block|,
literal|"table cell"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"row"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|Cell
block|,
name|ATSPI_ROLE_TABLE_CELL
block|,
literal|"table cell"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"cell"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|Link
block|,
name|ATSPI_ROLE_LINK
block|,
literal|"link"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"link"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|HelpBalloon
block|,
name|ATSPI_ROLE_DIALOG
block|,
literal|"dialog"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"help balloon"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|Assistant
block|,
name|ATSPI_ROLE_DIALOG
block|,
literal|"dialog"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"assistant"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|List
block|,
name|ATSPI_ROLE_LIST
block|,
literal|"list"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"list"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|ListItem
block|,
name|ATSPI_ROLE_LIST_ITEM
block|,
literal|"list item"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"list item"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|Tree
block|,
name|ATSPI_ROLE_TREE
block|,
literal|"tree"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"tree"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|TreeItem
block|,
name|ATSPI_ROLE_TABLE_CELL
block|,
literal|"tree item"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"tree item"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|PageTab
block|,
name|ATSPI_ROLE_PAGE_TAB
block|,
literal|"page tab"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"page tab"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|PropertyPage
block|,
name|ATSPI_ROLE_PAGE_TAB
block|,
literal|"page tab"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"property page"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|Indicator
block|,
name|ATSPI_ROLE_UNKNOWN
block|,
literal|"unknown"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"indicator"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|Graphic
block|,
name|ATSPI_ROLE_IMAGE
block|,
literal|"image"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"graphic"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|StaticText
block|,
name|ATSPI_ROLE_LABEL
block|,
literal|"label"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"label"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|EditableText
block|,
name|ATSPI_ROLE_TEXT
block|,
literal|"text"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"text"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|PushButton
block|,
name|ATSPI_ROLE_PUSH_BUTTON
block|,
literal|"push button"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"push button"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|CheckBox
block|,
name|ATSPI_ROLE_CHECK_BOX
block|,
literal|"check box"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"check box"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|RadioButton
block|,
name|ATSPI_ROLE_RADIO_BUTTON
block|,
literal|"radio button"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"radio box"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|ComboBox
block|,
name|ATSPI_ROLE_COMBO_BOX
block|,
literal|"combo box"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"combo box"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|ProgressBar
block|,
name|ATSPI_ROLE_PROGRESS_BAR
block|,
literal|"progress bar"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"progress bar"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|Dial
block|,
name|ATSPI_ROLE_DIAL
block|,
literal|"accelerator label"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"dial"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|HotkeyField
block|,
name|ATSPI_ROLE_TEXT
block|,
literal|"text"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"hotkey field"
argument_list|)
block|}
block|,
comment|//FIXME text?
block|{
name|QAccessible
operator|::
name|Slider
block|,
name|ATSPI_ROLE_SLIDER
block|,
literal|"slider"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"slider"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|SpinBox
block|,
name|ATSPI_ROLE_SPIN_BUTTON
block|,
literal|"spin button"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"spin box"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|Canvas
block|,
name|ATSPI_ROLE_CANVAS
block|,
literal|"canvas"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"canvas"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|Animation
block|,
name|ATSPI_ROLE_ANIMATION
block|,
literal|"animation"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"animation"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|Equation
block|,
name|ATSPI_ROLE_TEXT
block|,
literal|"text"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"equation"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|ButtonDropDown
block|,
name|ATSPI_ROLE_PUSH_BUTTON
block|,
literal|"push button"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"button drop down"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|ButtonMenu
block|,
name|ATSPI_ROLE_PUSH_BUTTON
block|,
literal|"push button"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"button menu"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|ButtonDropGrid
block|,
name|ATSPI_ROLE_PUSH_BUTTON
block|,
literal|"push button"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"button drop grid"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|Whitespace
block|,
name|ATSPI_ROLE_FILLER
block|,
literal|"filler"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"whitespace"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|PageTabList
block|,
name|ATSPI_ROLE_PAGE_TAB_LIST
block|,
literal|"page tab list"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"page tab list"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|Clock
block|,
name|ATSPI_ROLE_UNKNOWN
block|,
literal|"unknown"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"clock"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|Splitter
block|,
name|ATSPI_ROLE_SPLIT_PANE
block|,
literal|"split pane"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"splitter"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|LayeredPane
block|,
name|ATSPI_ROLE_LAYERED_PANE
block|,
literal|"layered pane"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"layered pane"
argument_list|)
block|}
block|,
block|{
name|QAccessible
operator|::
name|UserRole
block|,
name|ATSPI_ROLE_UNKNOWN
block|,
literal|"unknown"
block|,
name|QT_TR_NOOP
argument_list|(
literal|"user role"
argument_list|)
block|}
block|}
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|initializeConstantMappings
name|void
name|QSpiAccessibleBridge
operator|::
name|initializeConstantMappings
parameter_list|()
block|{
for|for
control|(
name|uint
name|i
init|=
literal|0
init|;
name|i
operator|<
sizeof|sizeof
argument_list|(
name|map
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|RoleMapping
argument_list|)
condition|;
operator|++
name|i
control|)
name|qSpiRoleMapping
operator|.
name|insert
argument_list|(
name|map
index|[
name|i
index|]
operator|.
name|role
argument_list|,
name|RoleNames
argument_list|(
name|map
index|[
name|i
index|]
operator|.
name|spiRole
argument_list|,
name|QLatin1String
argument_list|(
name|map
index|[
name|i
index|]
operator|.
name|name
argument_list|)
argument_list|,
name|tr
argument_list|(
name|map
index|[
name|i
index|]
operator|.
name|localizedName
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
