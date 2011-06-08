begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QACCESSIBLE_H
end_ifndef
begin_define
DECL|macro|QACCESSIBLE_H
define|#
directive|define
name|QACCESSIBLE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qrect.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qset.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvector.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvariant.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qcolor.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qevent.h>
end_include
begin_function
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
parameter_list|(
name|Gui
parameter_list|)
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
name|class
name|QAccessibleInterface
decl_stmt|;
name|class
name|Q_WIDGETS_EXPORT
name|QAccessible
decl_stmt|{ public:     enum Event
block|{
name|SoundPlayed
operator|=
literal|0x0001
operator|,
name|Alert
operator|=
literal|0x0002
operator|,
name|ForegroundChanged
operator|=
literal|0x0003
operator|,
name|MenuStart
operator|=
literal|0x0004
operator|,
name|MenuEnd
operator|=
literal|0x0005
operator|,
name|PopupMenuStart
operator|=
literal|0x0006
operator|,
name|PopupMenuEnd
operator|=
literal|0x0007
operator|,
name|ContextHelpStart
operator|=
literal|0x000C
operator|,
name|ContextHelpEnd
operator|=
literal|0x000D
operator|,
name|DragDropStart
operator|=
literal|0x000E
operator|,
name|DragDropEnd
operator|=
literal|0x000F
operator|,
name|DialogStart
operator|=
literal|0x0010
operator|,
name|DialogEnd
operator|=
literal|0x0011
operator|,
name|ScrollingStart
operator|=
literal|0x0012
operator|,
name|ScrollingEnd
operator|=
literal|0x0013
operator|,
name|MenuCommand
operator|=
literal|0x0018
operator|,
comment|// Values from IAccessible2
name|ActionChanged
operator|=
literal|0x0101
operator|,
name|ActiveDescendantChanged
operator|,
name|AttributeChanged
operator|,
name|DocumentContentChanged
operator|,
name|DocumentLoadComplete
operator|,
name|DocumentLoadStopped
operator|,
name|DocumentReload
operator|,
name|HyperlinkEndIndexChanged
operator|,
name|HyperlinkNumberOfAnchorsChanged
operator|,
name|HyperlinkSelectedLinkChanged
operator|,
name|HypertextLinkActivated
operator|,
name|HypertextLinkSelected
operator|,
name|HyperlinkStartIndexChanged
operator|,
name|HypertextChanged
operator|,
name|HypertextNLinksChanged
operator|,
name|ObjectAttributeChanged
operator|,
name|PageChanged
operator|,
name|SectionChanged
operator|,
name|TableCaptionChanged
operator|,
name|TableColumnDescriptionChanged
operator|,
name|TableColumnHeaderChanged
operator|,
name|TableModelChanged
operator|,
name|TableRowDescriptionChanged
operator|,
name|TableRowHeaderChanged
operator|,
name|TableSummaryChanged
operator|,
name|TextAttributeChanged
operator|,
name|TextCaretMoved
operator|,
comment|// TextChanged, deprecated, use TextUpdated
name|TextColumnChanged
operator|=
name|TextCaretMoved
operator|+
literal|2
operator|,
name|TextInserted
operator|,
name|TextRemoved
operator|,
name|TextUpdated
operator|,
name|TextSelectionChanged
operator|,
name|VisibleDataChanged
operator|,
name|ObjectCreated
operator|=
literal|0x8000
operator|,
name|ObjectDestroyed
operator|=
literal|0x8001
operator|,
name|ObjectShow
operator|=
literal|0x8002
operator|,
name|ObjectHide
operator|=
literal|0x8003
operator|,
name|ObjectReorder
operator|=
literal|0x8004
operator|,
name|Focus
operator|=
literal|0x8005
operator|,
name|Selection
operator|=
literal|0x8006
operator|,
name|SelectionAdd
operator|=
literal|0x8007
operator|,
name|SelectionRemove
operator|=
literal|0x8008
operator|,
name|SelectionWithin
operator|=
literal|0x8009
operator|,
name|StateChanged
operator|=
literal|0x800A
operator|,
name|LocationChanged
operator|=
literal|0x800B
operator|,
name|NameChanged
operator|=
literal|0x800C
operator|,
name|DescriptionChanged
operator|=
literal|0x800D
operator|,
name|ValueChanged
operator|=
literal|0x800E
operator|,
name|ParentChanged
operator|=
literal|0x800F
operator|,
name|HelpChanged
operator|=
literal|0x80A0
operator|,
name|DefaultActionChanged
operator|=
literal|0x80B0
operator|,
name|AcceleratorChanged
operator|=
literal|0x80C0
block|}
end_function
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_enum
enum|enum
name|StateFlag
block|{
name|Normal
init|=
literal|0x00000000
block|,
name|Unavailable
init|=
literal|0x00000001
block|,
name|Selected
init|=
literal|0x00000002
block|,
name|Focused
init|=
literal|0x00000004
block|,
name|Pressed
init|=
literal|0x00000008
block|,
name|Checked
init|=
literal|0x00000010
block|,
name|Mixed
init|=
literal|0x00000020
block|,
name|ReadOnly
init|=
literal|0x00000040
block|,
name|HotTracked
init|=
literal|0x00000080
block|,
name|DefaultButton
init|=
literal|0x00000100
block|,
name|Expanded
init|=
literal|0x00000200
block|,
name|Collapsed
init|=
literal|0x00000400
block|,
name|Busy
init|=
literal|0x00000800
block|,
comment|// Floating        = 0x00001000,
name|Marqueed
init|=
literal|0x00002000
block|,
name|Animated
init|=
literal|0x00004000
block|,
name|Invisible
init|=
literal|0x00008000
block|,
name|Offscreen
init|=
literal|0x00010000
block|,
name|Sizeable
init|=
literal|0x00020000
block|,
name|Movable
init|=
literal|0x00040000
block|,
name|SelfVoicing
init|=
literal|0x00080000
block|,
name|Focusable
init|=
literal|0x00100000
block|,
name|Selectable
init|=
literal|0x00200000
block|,
name|Linked
init|=
literal|0x00400000
block|,
name|Traversed
init|=
literal|0x00800000
block|,
name|MultiSelectable
init|=
literal|0x01000000
block|,
name|ExtSelectable
init|=
literal|0x02000000
block|,
comment|//AlertLow        = 0x04000000,
comment|//AlertMedium     = 0x08000000,
comment|//AlertHigh       = 0x10000000, /* reused for HasInvokeExtension */
name|Protected
init|=
literal|0x20000000
block|,
name|HasPopup
init|=
literal|0x40000000
block|,
name|Modal
init|=
literal|0x80000000
block|,
name|HasInvokeExtension
init|=
literal|0x10000000
comment|// internal
block|}
enum|;
end_enum
begin_expr_stmt
name|Q_DECLARE_FLAGS
argument_list|(
name|State
argument_list|,
name|StateFlag
argument_list|)
expr|enum
name|Role
block|{
name|NoRole
operator|=
literal|0x00000000
block|,
name|TitleBar
operator|=
literal|0x00000001
block|,
name|MenuBar
operator|=
literal|0x00000002
block|,
name|ScrollBar
operator|=
literal|0x00000003
block|,
name|Grip
operator|=
literal|0x00000004
block|,
name|Sound
operator|=
literal|0x00000005
block|,
name|Cursor
operator|=
literal|0x00000006
block|,
name|Caret
operator|=
literal|0x00000007
block|,
name|AlertMessage
operator|=
literal|0x00000008
block|,
name|Window
operator|=
literal|0x00000009
block|,
name|Client
operator|=
literal|0x0000000A
block|,
name|PopupMenu
operator|=
literal|0x0000000B
block|,
name|MenuItem
operator|=
literal|0x0000000C
block|,
name|ToolTip
operator|=
literal|0x0000000D
block|,
name|Application
operator|=
literal|0x0000000E
block|,
name|Document
operator|=
literal|0x0000000F
block|,
name|Pane
operator|=
literal|0x00000010
block|,
name|Chart
operator|=
literal|0x00000011
block|,
name|Dialog
operator|=
literal|0x00000012
block|,
name|Border
operator|=
literal|0x00000013
block|,
name|Grouping
operator|=
literal|0x00000014
block|,
name|Separator
operator|=
literal|0x00000015
block|,
name|ToolBar
operator|=
literal|0x00000016
block|,
name|StatusBar
operator|=
literal|0x00000017
block|,
name|Table
operator|=
literal|0x00000018
block|,
name|ColumnHeader
operator|=
literal|0x00000019
block|,
name|RowHeader
operator|=
literal|0x0000001A
block|,
name|Column
operator|=
literal|0x0000001B
block|,
name|Row
operator|=
literal|0x0000001C
block|,
name|Cell
operator|=
literal|0x0000001D
block|,
name|Link
operator|=
literal|0x0000001E
block|,
name|HelpBalloon
operator|=
literal|0x0000001F
block|,
name|Assistant
operator|=
literal|0x00000020
block|,
name|List
operator|=
literal|0x00000021
block|,
name|ListItem
operator|=
literal|0x00000022
block|,
name|Tree
operator|=
literal|0x00000023
block|,
name|TreeItem
operator|=
literal|0x00000024
block|,
name|PageTab
operator|=
literal|0x00000025
block|,
name|PropertyPage
operator|=
literal|0x00000026
block|,
name|Indicator
operator|=
literal|0x00000027
block|,
name|Graphic
operator|=
literal|0x00000028
block|,
name|StaticText
operator|=
literal|0x00000029
block|,
name|EditableText
operator|=
literal|0x0000002A
block|,
comment|// Editable, selectable, etc.
name|PushButton
operator|=
literal|0x0000002B
block|,
name|CheckBox
operator|=
literal|0x0000002C
block|,
name|RadioButton
operator|=
literal|0x0000002D
block|,
name|ComboBox
operator|=
literal|0x0000002E
block|,
comment|// DropList       = 0x0000002F,
name|ProgressBar
operator|=
literal|0x00000030
block|,
name|Dial
operator|=
literal|0x00000031
block|,
name|HotkeyField
operator|=
literal|0x00000032
block|,
name|Slider
operator|=
literal|0x00000033
block|,
name|SpinBox
operator|=
literal|0x00000034
block|,
name|Canvas
operator|=
literal|0x00000035
block|,
name|Animation
operator|=
literal|0x00000036
block|,
name|Equation
operator|=
literal|0x00000037
block|,
name|ButtonDropDown
operator|=
literal|0x00000038
block|,
name|ButtonMenu
operator|=
literal|0x00000039
block|,
name|ButtonDropGrid
operator|=
literal|0x0000003A
block|,
name|Whitespace
operator|=
literal|0x0000003B
block|,
name|PageTabList
operator|=
literal|0x0000003C
block|,
name|Clock
operator|=
literal|0x0000003D
block|,
name|Splitter
operator|=
literal|0x0000003E
block|,
comment|// Additional Qt roles where enum value does not map directly to MSAA:
name|LayeredPane
operator|=
literal|0x0000003F
block|,
name|UserRole
operator|=
literal|0x0000ffff
block|}
expr_stmt|;
end_expr_stmt
begin_enum
enum|enum
name|Text
block|{
name|Name
init|=
literal|0
block|,
name|Description
block|,
name|Value
block|,
name|Help
block|,
name|Accelerator
block|,
name|UserText
init|=
literal|0x0000ffff
block|}
enum|;
end_enum
begin_enum
enum|enum
name|RelationFlag
block|{
name|Unrelated
init|=
literal|0x00000000
block|,
name|Self
init|=
literal|0x00000001
block|,
name|Ancestor
init|=
literal|0x00000002
block|,
name|Child
init|=
literal|0x00000004
block|,
name|Descendent
init|=
literal|0x00000008
block|,
name|Sibling
init|=
literal|0x00000010
block|,
name|HierarchyMask
init|=
literal|0x000000ff
block|,
name|Up
init|=
literal|0x00000100
block|,
name|Down
init|=
literal|0x00000200
block|,
name|Left
init|=
literal|0x00000400
block|,
name|Right
init|=
literal|0x00000800
block|,
name|Covers
init|=
literal|0x00001000
block|,
name|Covered
init|=
literal|0x00002000
block|,
name|GeometryMask
init|=
literal|0x0000ff00
block|,
name|FocusChild
init|=
literal|0x00010000
block|,
name|Label
init|=
literal|0x00020000
block|,
name|Labelled
init|=
literal|0x00040000
block|,
name|Controller
init|=
literal|0x00080000
block|,
name|Controlled
init|=
literal|0x00100000
block|,
name|LogicalMask
init|=
literal|0x00ff0000
block|}
enum|;
end_enum
begin_expr_stmt
name|Q_DECLARE_FLAGS
argument_list|(
name|Relation
argument_list|,
name|RelationFlag
argument_list|)
expr|enum
name|Action
block|{
name|DefaultAction
operator|=
literal|0
block|,
name|Press
operator|=
operator|-
literal|1
block|,
name|FirstStandardAction
operator|=
name|Press
block|,
name|SetFocus
operator|=
operator|-
literal|2
block|,
name|Increase
operator|=
operator|-
literal|3
block|,
name|Decrease
operator|=
operator|-
literal|4
block|,
name|Accept
operator|=
operator|-
literal|5
block|,
name|Cancel
operator|=
operator|-
literal|6
block|,
name|Select
operator|=
operator|-
literal|7
block|,
name|ClearSelection
operator|=
operator|-
literal|8
block|,
name|RemoveSelection
operator|=
operator|-
literal|9
block|,
name|ExtendSelection
operator|=
operator|-
literal|10
block|,
name|AddToSelection
operator|=
operator|-
literal|11
block|,
name|LastStandardAction
operator|=
name|AddToSelection
block|}
expr_stmt|;
end_expr_stmt
begin_enum
enum|enum
name|Method
block|{
name|ListSupportedMethods
init|=
literal|0
block|,
name|SetCursorPosition
init|=
literal|1
block|,
name|GetCursorPosition
init|=
literal|2
block|,
name|ForegroundColor
init|=
literal|3
block|,
name|BackgroundColor
init|=
literal|4
block|}
enum|;
end_enum
begin_typedef
typedef|typedef
name|QAccessibleInterface
modifier|*
function_decl|(
modifier|*
name|InterfaceFactory
function_decl|)
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|,
name|QObject
modifier|*
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|UpdateHandler
function_decl|)
parameter_list|(
name|QObject
modifier|*
parameter_list|,
name|int
name|who
parameter_list|,
name|Event
name|reason
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|RootObjectHandler
function_decl|)
parameter_list|(
name|QObject
modifier|*
parameter_list|)
function_decl|;
end_typedef
begin_function_decl
specifier|static
name|void
name|installFactory
parameter_list|(
name|InterfaceFactory
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|void
name|removeFactory
parameter_list|(
name|InterfaceFactory
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|UpdateHandler
name|installUpdateHandler
parameter_list|(
name|UpdateHandler
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|RootObjectHandler
name|installRootObjectHandler
parameter_list|(
name|RootObjectHandler
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|QAccessibleInterface
modifier|*
name|queryAccessibleInterface
parameter_list|(
name|QObject
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|void
name|updateAccessibility
parameter_list|(
name|QObject
modifier|*
parameter_list|,
name|int
name|who
parameter_list|,
name|Event
name|reason
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|bool
name|isActive
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|void
name|setRootObject
parameter_list|(
name|QObject
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|void
name|initialize
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|void
name|cleanup
parameter_list|()
function_decl|;
end_function_decl
begin_label
name|private
label|:
end_label
begin_decl_stmt
specifier|static
name|UpdateHandler
name|updateHandler
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|static
name|RootObjectHandler
name|rootObjectHandler
decl_stmt|;
end_decl_stmt
begin_macro
unit|};
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QAccessible::State
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QAccessible::Relation
argument_list|)
end_macro
begin_decl_stmt
name|QT_END_NAMESPACE
name|Q_DECLARE_METATYPE
argument_list|(
name|QSet
operator|<
name|QAccessible
operator|::
name|Method
operator|>
argument_list|)
name|QT_BEGIN_NAMESPACE
name|namespace
name|QAccessible2
block|{
enum|enum
name|InterfaceType
block|{
name|TextInterface
block|,
name|EditableTextInterface
block|,
name|ValueInterface
block|,
name|TableInterface
block|,
name|ActionInterface
block|,
name|ImageInterface
block|}
enum|;
block|}
end_decl_stmt
begin_decl_stmt
DECL|variable|QAccessible2Interface
name|class
name|QAccessible2Interface
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAccessibleTextInterface
name|class
name|QAccessibleTextInterface
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAccessibleEditableTextInterface
name|class
name|QAccessibleEditableTextInterface
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAccessibleValueInterface
name|class
name|QAccessibleValueInterface
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAccessibleTableInterface
name|class
name|QAccessibleTableInterface
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAccessibleActionInterface
name|class
name|QAccessibleActionInterface
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAccessibleImageInterface
name|class
name|QAccessibleImageInterface
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QAccessibleInterface
range|:
name|public
name|QAccessible
block|{
name|public
operator|:
name|virtual
operator|~
name|QAccessibleInterface
argument_list|()
block|{}
comment|// check for valid pointers
name|virtual
name|bool
name|isValid
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|QObject
operator|*
name|object
argument_list|()
specifier|const
operator|=
literal|0
block|;
comment|// hierarchy
name|virtual
name|int
name|childCount
argument_list|()
specifier|const
operator|=
literal|0
block|;
name|virtual
name|int
name|indexOfChild
argument_list|(
argument|const QAccessibleInterface *
argument_list|)
specifier|const
operator|=
literal|0
block|;
comment|// relations
name|virtual
name|Relation
name|relationTo
argument_list|(
argument|int child
argument_list|,
argument|const QAccessibleInterface *other
argument_list|,
argument|int otherChild
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|int
name|childAt
argument_list|(
argument|int x
argument_list|,
argument|int y
argument_list|)
specifier|const
operator|=
literal|0
block|;
comment|// navigation
name|virtual
name|int
name|navigate
argument_list|(
argument|RelationFlag relation
argument_list|,
argument|int index
argument_list|,
argument|QAccessibleInterface **iface
argument_list|)
specifier|const
operator|=
literal|0
block|;
comment|// properties and state
name|virtual
name|QString
name|text
argument_list|(
argument|Text t
argument_list|,
argument|int child
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|void
name|setText
argument_list|(
argument|Text t
argument_list|,
argument|int child
argument_list|,
argument|const QString&text
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|QRect
name|rect
argument_list|(
argument|int child
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|Role
name|role
argument_list|(
argument|int child
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|State
name|state
argument_list|(
argument|int child
argument_list|)
specifier|const
operator|=
literal|0
block|;
comment|// action
name|virtual
name|int
name|userActionCount
argument_list|(
argument|int child
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|QString
name|actionText
argument_list|(
argument|int action
argument_list|,
argument|Text t
argument_list|,
argument|int child
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|bool
name|doAction
argument_list|(
argument|int action
argument_list|,
argument|int child
argument_list|,
argument|const QVariantList&params = QVariantList()
argument_list|)
operator|=
literal|0
block|;
name|QVariant
name|invokeMethod
argument_list|(
argument|Method method
argument_list|,
argument|int child =
literal|0
argument_list|,
argument|const QVariantList&params = QVariantList()
argument_list|)
block|;
specifier|inline
name|QSet
operator|<
name|Method
operator|>
name|supportedMethods
argument_list|()
block|{
return|return
name|qvariant_cast
operator|<
name|QSet
operator|<
name|Method
operator|>
expr|>
operator|(
name|invokeMethod
argument_list|(
name|ListSupportedMethods
argument_list|)
operator|)
return|;
block|}
specifier|inline
name|QColor
name|foregroundColor
argument_list|()
block|{
return|return
name|qvariant_cast
operator|<
name|QColor
operator|>
operator|(
name|invokeMethod
argument_list|(
name|ForegroundColor
argument_list|)
operator|)
return|;
block|}
specifier|inline
name|QColor
name|backgroundColor
argument_list|()
block|{
return|return
name|qvariant_cast
operator|<
name|QColor
operator|>
operator|(
name|invokeMethod
argument_list|(
name|BackgroundColor
argument_list|)
operator|)
return|;
block|}
specifier|inline
name|QAccessibleTextInterface
operator|*
name|textInterface
argument_list|()
block|{
return|return
name|reinterpret_cast
operator|<
name|QAccessibleTextInterface
operator|*
operator|>
operator|(
name|cast_helper
argument_list|(
name|QAccessible2
operator|::
name|TextInterface
argument_list|)
operator|)
return|;
block|}
specifier|inline
name|QAccessibleEditableTextInterface
operator|*
name|editableTextInterface
argument_list|()
block|{
return|return
name|reinterpret_cast
operator|<
name|QAccessibleEditableTextInterface
operator|*
operator|>
operator|(
name|cast_helper
argument_list|(
name|QAccessible2
operator|::
name|EditableTextInterface
argument_list|)
operator|)
return|;
block|}
specifier|inline
name|QAccessibleValueInterface
operator|*
name|valueInterface
argument_list|()
block|{
return|return
name|reinterpret_cast
operator|<
name|QAccessibleValueInterface
operator|*
operator|>
operator|(
name|cast_helper
argument_list|(
name|QAccessible2
operator|::
name|ValueInterface
argument_list|)
operator|)
return|;
block|}
specifier|inline
name|QAccessibleTableInterface
operator|*
name|tableInterface
argument_list|()
block|{
return|return
name|reinterpret_cast
operator|<
name|QAccessibleTableInterface
operator|*
operator|>
operator|(
name|cast_helper
argument_list|(
name|QAccessible2
operator|::
name|TableInterface
argument_list|)
operator|)
return|;
block|}
specifier|inline
name|QAccessibleActionInterface
operator|*
name|actionInterface
argument_list|()
block|{
return|return
name|reinterpret_cast
operator|<
name|QAccessibleActionInterface
operator|*
operator|>
operator|(
name|cast_helper
argument_list|(
name|QAccessible2
operator|::
name|ActionInterface
argument_list|)
operator|)
return|;
block|}
specifier|inline
name|QAccessibleImageInterface
operator|*
name|imageInterface
argument_list|()
block|{
return|return
name|reinterpret_cast
operator|<
name|QAccessibleImageInterface
operator|*
operator|>
operator|(
name|cast_helper
argument_list|(
name|QAccessible2
operator|::
name|ImageInterface
argument_list|)
operator|)
return|;
block|}
name|private
operator|:
name|QAccessible2Interface
operator|*
name|cast_helper
argument_list|(
name|QAccessible2
operator|::
name|InterfaceType
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QAccessibleInterfaceEx
range|:
name|public
name|QAccessibleInterface
block|{
name|public
operator|:
name|virtual
name|QVariant
name|invokeMethodEx
argument_list|(
argument|Method method
argument_list|,
argument|int child
argument_list|,
argument|const QVariantList&params
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|QVariant
name|virtual_hook
argument_list|(
specifier|const
name|QVariant
operator|&
name|data
argument_list|)
block|;
name|virtual
name|QAccessible2Interface
operator|*
name|interface_cast
argument_list|(
argument|QAccessible2::InterfaceType
argument_list|)
block|{
return|return
literal|0
return|;
block|}
expr|}
block|;
name|class
name|Q_WIDGETS_EXPORT
name|QAccessibleEvent
operator|:
name|public
name|QEvent
block|{
name|public
operator|:
specifier|inline
name|QAccessibleEvent
argument_list|(
argument|Type type
argument_list|,
argument|int child
argument_list|)
block|;
specifier|inline
name|int
name|child
argument_list|()
specifier|const
block|{
return|return
name|c
return|;
block|}
specifier|inline
name|QString
name|value
argument_list|()
specifier|const
block|{
return|return
name|val
return|;
block|}
specifier|inline
name|void
name|setValue
argument_list|(
argument|const QString&aText
argument_list|)
block|{
name|val
operator|=
name|aText
block|; }
name|private
operator|:
name|int
name|c
block|;
name|QString
name|val
block|; }
block|;
DECL|function|QAccessibleEvent
specifier|inline
name|QAccessibleEvent
operator|::
name|QAccessibleEvent
argument_list|(
argument|Type atype
argument_list|,
argument|int achild
argument_list|)
operator|:
name|QEvent
argument_list|(
name|atype
argument_list|)
block|,
name|c
argument_list|(
argument|achild
argument_list|)
block|{}
DECL|macro|QAccessibleInterface_iid
define|#
directive|define
name|QAccessibleInterface_iid
value|"com.trolltech.Qt.QAccessibleInterface"
name|Q_DECLARE_INTERFACE
argument_list|(
argument|QAccessibleInterface
argument_list|,
argument|QAccessibleInterface_iid
argument_list|)
endif|#
directive|endif
comment|// QT_NO_ACCESSIBILITY
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QACCESSIBLE_H
end_comment
end_unit
