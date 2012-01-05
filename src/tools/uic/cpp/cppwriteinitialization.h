begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|CPPWRITEINITIALIZATION_H
end_ifndef
begin_define
DECL|macro|CPPWRITEINITIALIZATION_H
define|#
directive|define
name|CPPWRITEINITIALIZATION_H
end_define
begin_include
include|#
directive|include
file|"treewalker.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QPair>
end_include
begin_include
include|#
directive|include
file|<QtCore/QHash>
end_include
begin_include
include|#
directive|include
file|<QtCore/QSet>
end_include
begin_include
include|#
directive|include
file|<QtCore/QMap>
end_include
begin_include
include|#
directive|include
file|<QtCore/QStack>
end_include
begin_include
include|#
directive|include
file|<QtCore/QTextStream>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|Driver
name|class
name|Driver
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|Uic
name|class
name|Uic
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DomBrush
name|class
name|DomBrush
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DomFont
name|class
name|DomFont
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DomResourceIcon
name|class
name|DomResourceIcon
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|DomSizePolicy
name|class
name|DomSizePolicy
decl_stmt|;
end_decl_stmt
begin_struct_decl
struct_decl|struct
name|Option
struct_decl|;
end_struct_decl
begin_decl_stmt
name|namespace
name|CPP
block|{
comment|// Handle for a flat DOM font to get comparison functionality required for maps
name|class
name|FontHandle
block|{
name|public
label|:
name|FontHandle
argument_list|(
specifier|const
name|DomFont
operator|*
name|domFont
argument_list|)
expr_stmt|;
name|int
name|compare
argument_list|(
specifier|const
name|FontHandle
operator|&
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
specifier|const
name|DomFont
modifier|*
name|m_domFont
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
operator|&&
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
operator|&&
operator|(
name|__GNUC__
operator|==
literal|3
operator|&&
name|__GNUC_MINOR__
operator|==
literal|3
operator|)
name|friend
name|uint
name|qHash
parameter_list|(
specifier|const
name|FontHandle
modifier|&
parameter_list|)
function_decl|;
endif|#
directive|endif
block|}
empty_stmt|;
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|FontHandle
operator|&
name|f1
operator|,
specifier|const
name|FontHandle
operator|&
name|f2
operator|)
block|{
return|return
name|f1
operator|.
name|compare
argument_list|(
name|f2
argument_list|)
operator|==
literal|0
return|;
block|}
specifier|inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|FontHandle
operator|&
name|f1
operator|,
specifier|const
name|FontHandle
operator|&
name|f2
operator|)
block|{
return|return
name|f1
operator|.
name|compare
argument_list|(
name|f2
argument_list|)
operator|<
literal|0
return|;
block|}
comment|// Handle for a flat DOM icon to get comparison functionality required for maps
name|class
name|IconHandle
block|{
name|public
label|:
name|IconHandle
argument_list|(
specifier|const
name|DomResourceIcon
operator|*
name|domIcon
argument_list|)
expr_stmt|;
name|int
name|compare
argument_list|(
specifier|const
name|IconHandle
operator|&
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
specifier|const
name|DomResourceIcon
modifier|*
name|m_domIcon
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
operator|&&
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
operator|&&
operator|(
name|__GNUC__
operator|==
literal|3
operator|&&
name|__GNUC_MINOR__
operator|==
literal|3
operator|)
name|friend
name|uint
name|qHash
parameter_list|(
specifier|const
name|IconHandle
modifier|&
parameter_list|)
function_decl|;
endif|#
directive|endif
block|}
empty_stmt|;
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|IconHandle
operator|&
name|i1
operator|,
specifier|const
name|IconHandle
operator|&
name|i2
operator|)
block|{
return|return
name|i1
operator|.
name|compare
argument_list|(
name|i2
argument_list|)
operator|==
literal|0
return|;
block|}
specifier|inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|IconHandle
operator|&
name|i1
operator|,
specifier|const
name|IconHandle
operator|&
name|i2
operator|)
block|{
return|return
name|i1
operator|.
name|compare
argument_list|(
name|i2
argument_list|)
operator|<
literal|0
return|;
block|}
comment|// Handle for a flat DOM size policy to get comparison functionality required for maps
name|class
name|SizePolicyHandle
block|{
name|public
label|:
name|SizePolicyHandle
argument_list|(
specifier|const
name|DomSizePolicy
operator|*
name|domSizePolicy
argument_list|)
expr_stmt|;
name|int
name|compare
argument_list|(
specifier|const
name|SizePolicyHandle
operator|&
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
specifier|const
name|DomSizePolicy
modifier|*
name|m_domSizePolicy
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
operator|&&
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
operator|&&
operator|(
name|__GNUC__
operator|==
literal|3
operator|&&
name|__GNUC_MINOR__
operator|==
literal|3
operator|)
name|friend
name|uint
name|qHash
parameter_list|(
specifier|const
name|SizePolicyHandle
modifier|&
parameter_list|)
function_decl|;
endif|#
directive|endif
block|}
empty_stmt|;
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|SizePolicyHandle
operator|&
name|f1
operator|,
specifier|const
name|SizePolicyHandle
operator|&
name|f2
operator|)
block|{
return|return
name|f1
operator|.
name|compare
argument_list|(
name|f2
argument_list|)
operator|==
literal|0
return|;
block|}
if|#
directive|if
operator|!
operator|(
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
operator|&&
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
operator|&&
operator|(
name|__GNUC__
operator|==
literal|3
operator|&&
name|__GNUC_MINOR__
operator|==
literal|3
operator|)
operator|)
specifier|inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|SizePolicyHandle
operator|&
name|f1
operator|,
specifier|const
name|SizePolicyHandle
operator|&
name|f2
operator|)
block|{
return|return
name|f1
operator|.
name|compare
argument_list|(
name|f2
argument_list|)
operator|<
literal|0
return|;
block|}
endif|#
directive|endif
name|struct
name|WriteInitialization
range|:
name|public
name|TreeWalker
block|{
typedef|typedef
name|QList
operator|<
name|DomProperty
operator|*
operator|>
name|DomPropertyList
expr_stmt|;
typedef|typedef
name|QHash
operator|<
name|QString
operator|,
name|DomProperty
operator|*
operator|>
name|DomPropertyMap
expr_stmt|;
name|WriteInitialization
argument_list|(
argument|Uic *uic
argument_list|,
argument|bool activateScripts
argument_list|)
empty_stmt|;
comment|//
comment|// widgets
comment|//
name|void
name|acceptUI
parameter_list|(
name|DomUI
modifier|*
name|node
parameter_list|)
function_decl|;
name|void
name|acceptWidget
parameter_list|(
name|DomWidget
modifier|*
name|node
parameter_list|)
function_decl|;
name|void
name|acceptWidgetScripts
parameter_list|(
specifier|const
name|DomScripts
modifier|&
parameter_list|,
name|DomWidget
modifier|*
name|node
parameter_list|,
specifier|const
name|DomWidgets
modifier|&
name|childWidgets
parameter_list|)
function_decl|;
name|void
name|acceptLayout
parameter_list|(
name|DomLayout
modifier|*
name|node
parameter_list|)
function_decl|;
name|void
name|acceptSpacer
parameter_list|(
name|DomSpacer
modifier|*
name|node
parameter_list|)
function_decl|;
name|void
name|acceptLayoutItem
parameter_list|(
name|DomLayoutItem
modifier|*
name|node
parameter_list|)
function_decl|;
comment|//
comment|// actions
comment|//
name|void
name|acceptActionGroup
parameter_list|(
name|DomActionGroup
modifier|*
name|node
parameter_list|)
function_decl|;
name|void
name|acceptAction
parameter_list|(
name|DomAction
modifier|*
name|node
parameter_list|)
function_decl|;
name|void
name|acceptActionRef
parameter_list|(
name|DomActionRef
modifier|*
name|node
parameter_list|)
function_decl|;
comment|//
comment|// tab stops
comment|//
name|void
name|acceptTabStops
parameter_list|(
name|DomTabStops
modifier|*
name|tabStops
parameter_list|)
function_decl|;
comment|//
comment|// custom widgets
comment|//
name|void
name|acceptCustomWidgets
parameter_list|(
name|DomCustomWidgets
modifier|*
name|node
parameter_list|)
function_decl|;
name|void
name|acceptCustomWidget
parameter_list|(
name|DomCustomWidget
modifier|*
name|node
parameter_list|)
function_decl|;
comment|//
comment|// layout defaults/functions
comment|//
name|void
name|acceptLayoutDefault
parameter_list|(
name|DomLayoutDefault
modifier|*
name|node
parameter_list|)
block|{
name|m_LayoutDefaultHandler
operator|.
name|acceptLayoutDefault
argument_list|(
name|node
argument_list|)
expr_stmt|;
block|}
name|void
name|acceptLayoutFunction
parameter_list|(
name|DomLayoutFunction
modifier|*
name|node
parameter_list|)
block|{
name|m_LayoutDefaultHandler
operator|.
name|acceptLayoutFunction
argument_list|(
name|node
argument_list|)
expr_stmt|;
block|}
comment|//
comment|// signal/slot connections
comment|//
name|void
name|acceptConnection
parameter_list|(
name|DomConnection
modifier|*
name|connection
parameter_list|)
function_decl|;
comment|//
comment|// images
comment|//
name|void
name|acceptImage
parameter_list|(
name|DomImage
modifier|*
name|image
parameter_list|)
function_decl|;
enum|enum
block|{
name|Use43UiFile
init|=
literal|0
block|,
name|TopLevelMargin
block|,
name|ChildMargin
block|,
name|SubLayoutMargin
block|}
enum|;
name|private
label|:
specifier|static
name|QString
name|domColor2QString
parameter_list|(
specifier|const
name|DomColor
modifier|*
name|c
parameter_list|)
function_decl|;
name|QString
name|iconCall
parameter_list|(
specifier|const
name|DomProperty
modifier|*
name|prop
parameter_list|)
function_decl|;
name|QString
name|pixCall
argument_list|(
specifier|const
name|DomProperty
operator|*
name|prop
argument_list|)
decl|const
decl_stmt|;
name|QString
name|pixCall
argument_list|(
specifier|const
name|QString
operator|&
name|type
argument_list|,
specifier|const
name|QString
operator|&
name|text
argument_list|)
decl|const
decl_stmt|;
name|QString
name|trCall
argument_list|(
specifier|const
name|QString
operator|&
name|str
argument_list|,
specifier|const
name|QString
operator|&
name|comment
operator|=
name|QString
argument_list|()
argument_list|)
decl|const
decl_stmt|;
name|QString
name|trCall
argument_list|(
name|DomString
operator|*
name|str
argument_list|,
specifier|const
name|QString
operator|&
name|defaultString
operator|=
name|QString
argument_list|()
argument_list|)
decl|const
decl_stmt|;
name|QString
name|noTrCall
argument_list|(
name|DomString
operator|*
name|str
argument_list|,
specifier|const
name|QString
operator|&
name|defaultString
operator|=
name|QString
argument_list|()
argument_list|)
decl|const
decl_stmt|;
name|QString
name|autoTrCall
argument_list|(
name|DomString
operator|*
name|str
argument_list|,
specifier|const
name|QString
operator|&
name|defaultString
operator|=
name|QString
argument_list|()
argument_list|)
decl|const
decl_stmt|;
name|QTextStream
modifier|&
name|autoTrOutput
parameter_list|(
name|DomString
modifier|*
name|str
parameter_list|,
specifier|const
name|QString
modifier|&
name|defaultString
init|=
name|QString
argument_list|()
parameter_list|)
function_decl|;
comment|// Apply a comma-separated list of values using a function "setSomething(int idx, value)"
name|void
name|writePropertyList
parameter_list|(
specifier|const
name|QString
modifier|&
name|varName
parameter_list|,
specifier|const
name|QString
modifier|&
name|setFunction
parameter_list|,
specifier|const
name|QString
modifier|&
name|value
parameter_list|,
specifier|const
name|QString
modifier|&
name|defaultValue
parameter_list|)
function_decl|;
enum|enum
block|{
name|WritePropertyIgnoreMargin
init|=
literal|1
block|,
name|WritePropertyIgnoreSpacing
init|=
literal|2
block|,
name|WritePropertyIgnoreObjectName
init|=
literal|4
block|}
enum|;
name|void
name|writeProperties
parameter_list|(
specifier|const
name|QString
modifier|&
name|varName
parameter_list|,
specifier|const
name|QString
modifier|&
name|className
parameter_list|,
specifier|const
name|DomPropertyList
modifier|&
name|lst
parameter_list|,
name|unsigned
name|flags
init|=
literal|0
parameter_list|)
function_decl|;
name|void
name|writeColorGroup
parameter_list|(
name|DomColorGroup
modifier|*
name|colorGroup
parameter_list|,
specifier|const
name|QString
modifier|&
name|group
parameter_list|,
specifier|const
name|QString
modifier|&
name|paletteName
parameter_list|)
function_decl|;
name|void
name|writeBrush
parameter_list|(
specifier|const
name|DomBrush
modifier|*
name|brush
parameter_list|,
specifier|const
name|QString
modifier|&
name|brushName
parameter_list|)
function_decl|;
comment|//
comment|// special initialization
comment|//
name|class
name|Item
block|{
name|public
label|:
name|Item
argument_list|(
specifier|const
name|QString
operator|&
name|itemClassName
argument_list|,
specifier|const
name|QString
operator|&
name|indent
argument_list|,
name|QTextStream
operator|&
name|setupUiStream
argument_list|,
name|QTextStream
operator|&
name|retranslateUiStream
argument_list|,
name|Driver
operator|*
name|driver
argument_list|)
expr_stmt|;
operator|~
name|Item
argument_list|()
expr_stmt|;
enum|enum
name|EmptyItemPolicy
block|{
name|DontConstruct
block|,
name|ConstructItemOnly
block|,
name|ConstructItemAndVariable
block|}
enum|;
name|QString
name|writeSetupUi
parameter_list|(
specifier|const
name|QString
modifier|&
name|parent
parameter_list|,
name|EmptyItemPolicy
name|emptyItemPolicy
init|=
name|ConstructItemOnly
parameter_list|)
function_decl|;
name|void
name|writeRetranslateUi
parameter_list|(
specifier|const
name|QString
modifier|&
name|parentPath
parameter_list|)
function_decl|;
name|void
name|addSetter
parameter_list|(
specifier|const
name|QString
modifier|&
name|setter
parameter_list|,
specifier|const
name|QString
modifier|&
name|directive
init|=
name|QString
argument_list|()
parameter_list|,
name|bool
name|translatable
init|=
name|false
parameter_list|)
function_decl|;
comment|// don't call it if you already added *this as a child of another Item
name|void
name|addChild
parameter_list|(
name|Item
modifier|*
name|child
parameter_list|)
function_decl|;
comment|// all setters should already been added
name|int
name|setupUiCount
argument_list|()
specifier|const
block|{
return|return
name|m_setupUiData
operator|.
name|setters
operator|.
name|count
argument_list|()
return|;
block|}
name|int
name|retranslateUiCount
argument_list|()
specifier|const
block|{
return|return
name|m_retranslateUiData
operator|.
name|setters
operator|.
name|count
argument_list|()
return|;
block|}
name|private
label|:
struct|struct
name|ItemData
block|{
name|ItemData
argument_list|()
operator|:
name|policy
argument_list|(
argument|DontGenerate
argument_list|)
block|{}
name|QMultiMap
operator|<
name|QString
operator|,
name|QString
operator|>
name|setters
expr_stmt|;
comment|// directive to setter
name|QSet
operator|<
name|QString
operator|>
name|directives
expr_stmt|;
enum|enum
name|TemporaryVariableGeneratorPolicy
block|{
comment|// policies with priority, number describes the priority
name|DontGenerate
init|=
literal|1
block|,
name|GenerateWithMultiDirective
init|=
literal|2
block|,
name|Generate
init|=
literal|3
block|}
name|policy
enum|;
block|}
struct|;
name|ItemData
name|m_setupUiData
decl_stmt|;
name|ItemData
name|m_retranslateUiData
decl_stmt|;
name|QList
operator|<
name|Item
operator|*
operator|>
name|m_children
expr_stmt|;
name|Item
modifier|*
name|m_parent
decl_stmt|;
specifier|const
name|QString
name|m_itemClassName
decl_stmt|;
specifier|const
name|QString
name|m_indent
decl_stmt|;
name|QTextStream
modifier|&
name|m_setupUiStream
decl_stmt|;
name|QTextStream
modifier|&
name|m_retranslateUiStream
decl_stmt|;
name|Driver
modifier|*
name|m_driver
decl_stmt|;
block|}
empty_stmt|;
name|void
name|addInitializer
argument_list|(
name|Item
operator|*
name|item
argument_list|,
specifier|const
name|QString
operator|&
name|name
argument_list|,
name|int
name|column
argument_list|,
specifier|const
name|QString
operator|&
name|value
argument_list|,
specifier|const
name|QString
operator|&
name|directive
operator|=
name|QString
argument_list|()
argument_list|,
name|bool
name|translatable
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
name|void
name|addQtFlagsInitializer
argument_list|(
name|Item
operator|*
name|item
argument_list|,
specifier|const
name|DomPropertyMap
operator|&
name|properties
argument_list|,
specifier|const
name|QString
operator|&
name|name
argument_list|,
name|int
name|column
operator|=
operator|-
literal|1
argument_list|)
decl|const
decl_stmt|;
name|void
name|addQtEnumInitializer
argument_list|(
name|Item
operator|*
name|item
argument_list|,
specifier|const
name|DomPropertyMap
operator|&
name|properties
argument_list|,
specifier|const
name|QString
operator|&
name|name
argument_list|,
name|int
name|column
operator|=
operator|-
literal|1
argument_list|)
decl|const
decl_stmt|;
name|void
name|addBrushInitializer
parameter_list|(
name|Item
modifier|*
name|item
parameter_list|,
specifier|const
name|DomPropertyMap
modifier|&
name|properties
parameter_list|,
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
name|int
name|column
init|=
operator|-
literal|1
parameter_list|)
function_decl|;
name|void
name|addStringInitializer
argument_list|(
name|Item
operator|*
name|item
argument_list|,
specifier|const
name|DomPropertyMap
operator|&
name|properties
argument_list|,
specifier|const
name|QString
operator|&
name|name
argument_list|,
name|int
name|column
operator|=
operator|-
literal|1
argument_list|,
specifier|const
name|QString
operator|&
name|directive
operator|=
name|QString
argument_list|()
argument_list|)
decl|const
decl_stmt|;
name|void
name|addCommonInitializers
parameter_list|(
name|Item
modifier|*
name|item
parameter_list|,
specifier|const
name|DomPropertyMap
modifier|&
name|properties
parameter_list|,
name|int
name|column
init|=
operator|-
literal|1
parameter_list|)
function_decl|;
name|void
name|initializeMenu
parameter_list|(
name|DomWidget
modifier|*
name|w
parameter_list|,
specifier|const
name|QString
modifier|&
name|parentWidget
parameter_list|)
function_decl|;
name|void
name|initializeComboBox
parameter_list|(
name|DomWidget
modifier|*
name|w
parameter_list|)
function_decl|;
name|void
name|initializeListWidget
parameter_list|(
name|DomWidget
modifier|*
name|w
parameter_list|)
function_decl|;
name|void
name|initializeTreeWidget
parameter_list|(
name|DomWidget
modifier|*
name|w
parameter_list|)
function_decl|;
name|QList
operator|<
name|Item
operator|*
operator|>
name|initializeTreeWidgetItems
argument_list|(
specifier|const
name|QList
operator|<
name|DomItem
operator|*
operator|>
operator|&
name|domItems
argument_list|)
expr_stmt|;
name|void
name|initializeTableWidget
parameter_list|(
name|DomWidget
modifier|*
name|w
parameter_list|)
function_decl|;
name|QString
name|disableSorting
parameter_list|(
name|DomWidget
modifier|*
name|w
parameter_list|,
specifier|const
name|QString
modifier|&
name|varName
parameter_list|)
function_decl|;
name|void
name|enableSorting
parameter_list|(
name|DomWidget
modifier|*
name|w
parameter_list|,
specifier|const
name|QString
modifier|&
name|varName
parameter_list|,
specifier|const
name|QString
modifier|&
name|tempName
parameter_list|)
function_decl|;
name|QString
name|findDeclaration
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
name|DomWidget
modifier|*
name|findWidget
parameter_list|(
specifier|const
name|QLatin1String
modifier|&
name|widgetClass
parameter_list|)
function_decl|;
name|DomImage
modifier|*
name|findImage
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
decl|const
decl_stmt|;
name|bool
name|isValidObject
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
name|QString
name|writeFontProperties
parameter_list|(
specifier|const
name|DomFont
modifier|*
name|f
parameter_list|)
function_decl|;
name|QString
name|writeIconProperties
parameter_list|(
specifier|const
name|DomResourceIcon
modifier|*
name|i
parameter_list|)
function_decl|;
name|QString
name|writeSizePolicy
parameter_list|(
specifier|const
name|DomSizePolicy
modifier|*
name|sp
parameter_list|)
function_decl|;
name|QString
name|writeBrushInitialization
parameter_list|(
specifier|const
name|DomBrush
modifier|*
name|brush
parameter_list|)
function_decl|;
name|void
name|addButtonGroup
parameter_list|(
specifier|const
name|DomWidget
modifier|*
name|node
parameter_list|,
specifier|const
name|QString
modifier|&
name|varName
parameter_list|)
function_decl|;
name|void
name|addWizardPage
parameter_list|(
specifier|const
name|QString
modifier|&
name|pageVarName
parameter_list|,
specifier|const
name|DomWidget
modifier|*
name|page
parameter_list|,
specifier|const
name|QString
modifier|&
name|parentWidget
parameter_list|)
function_decl|;
specifier|const
name|Uic
modifier|*
name|m_uic
decl_stmt|;
name|Driver
modifier|*
name|m_driver
decl_stmt|;
name|QTextStream
modifier|&
name|m_output
decl_stmt|;
specifier|const
name|Option
modifier|&
name|m_option
decl_stmt|;
name|QString
name|m_indent
decl_stmt|;
name|QString
name|m_dindent
decl_stmt|;
name|bool
name|m_stdsetdef
decl_stmt|;
struct|struct
name|Buddy
block|{
name|Buddy
argument_list|(
specifier|const
name|QString
operator|&
name|oN
argument_list|,
specifier|const
name|QString
operator|&
name|b
argument_list|)
operator|:
name|objName
argument_list|(
name|oN
argument_list|)
operator|,
name|buddy
argument_list|(
argument|b
argument_list|)
block|{}
name|QString
name|objName
expr_stmt|;
name|QString
name|buddy
decl_stmt|;
block|}
struct|;
name|QStack
operator|<
name|DomWidget
operator|*
operator|>
name|m_widgetChain
expr_stmt|;
name|QStack
operator|<
name|DomLayout
operator|*
operator|>
name|m_layoutChain
expr_stmt|;
name|QStack
operator|<
name|DomActionGroup
operator|*
operator|>
name|m_actionGroupChain
expr_stmt|;
name|QList
operator|<
name|Buddy
operator|>
name|m_buddies
expr_stmt|;
name|QSet
operator|<
name|QString
operator|>
name|m_buttonGroups
expr_stmt|;
name|QHash
operator|<
name|QString
operator|,
name|DomWidget
operator|*
operator|>
name|m_registeredWidgets
expr_stmt|;
name|QHash
operator|<
name|QString
operator|,
name|DomImage
operator|*
operator|>
name|m_registeredImages
expr_stmt|;
name|QHash
operator|<
name|QString
operator|,
name|DomAction
operator|*
operator|>
name|m_registeredActions
expr_stmt|;
typedef|typedef
name|QHash
operator|<
name|uint
operator|,
name|QString
operator|>
name|ColorBrushHash
expr_stmt|;
name|ColorBrushHash
name|m_colorBrushHash
decl_stmt|;
comment|// Map from font properties to  font variable name for reuse
comment|// Map from size policy to  variable for reuse
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_MAC
argument_list|)
operator|&&
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
operator|&&
operator|(
name|__GNUC__
operator|==
literal|3
operator|&&
name|__GNUC_MINOR__
operator|==
literal|3
operator|)
typedef|typedef
name|QHash
operator|<
name|FontHandle
operator|,
name|QString
operator|>
name|FontPropertiesNameMap
expr_stmt|;
typedef|typedef
name|QHash
operator|<
name|IconHandle
operator|,
name|QString
operator|>
name|IconPropertiesNameMap
expr_stmt|;
typedef|typedef
name|QHash
operator|<
name|SizePolicyHandle
operator|,
name|QString
operator|>
name|SizePolicyNameMap
expr_stmt|;
else|#
directive|else
typedef|typedef
name|QMap
operator|<
name|FontHandle
operator|,
name|QString
operator|>
name|FontPropertiesNameMap
expr_stmt|;
typedef|typedef
name|QMap
operator|<
name|IconHandle
operator|,
name|QString
operator|>
name|IconPropertiesNameMap
expr_stmt|;
typedef|typedef
name|QMap
operator|<
name|SizePolicyHandle
operator|,
name|QString
operator|>
name|SizePolicyNameMap
expr_stmt|;
endif|#
directive|endif
name|FontPropertiesNameMap
name|m_fontPropertiesNameMap
decl_stmt|;
name|IconPropertiesNameMap
name|m_iconPropertiesNameMap
decl_stmt|;
name|SizePolicyNameMap
name|m_sizePolicyNameMap
decl_stmt|;
name|class
name|LayoutDefaultHandler
block|{
name|public
label|:
name|LayoutDefaultHandler
argument_list|()
expr_stmt|;
name|void
name|acceptLayoutDefault
parameter_list|(
name|DomLayoutDefault
modifier|*
name|node
parameter_list|)
function_decl|;
name|void
name|acceptLayoutFunction
parameter_list|(
name|DomLayoutFunction
modifier|*
name|node
parameter_list|)
function_decl|;
comment|// Write out the layout margin and spacing properties applying the defaults.
name|void
name|writeProperties
argument_list|(
specifier|const
name|QString
operator|&
name|indent
argument_list|,
specifier|const
name|QString
operator|&
name|varName
argument_list|,
specifier|const
name|DomPropertyMap
operator|&
name|pm
argument_list|,
name|int
name|marginType
argument_list|,
name|bool
name|suppressMarginDefault
argument_list|,
name|QTextStream
operator|&
name|str
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|void
name|writeProperty
argument_list|(
name|int
name|p
argument_list|,
specifier|const
name|QString
operator|&
name|indent
argument_list|,
specifier|const
name|QString
operator|&
name|objectName
argument_list|,
specifier|const
name|DomPropertyMap
operator|&
name|pm
argument_list|,
specifier|const
name|QString
operator|&
name|propertyName
argument_list|,
specifier|const
name|QString
operator|&
name|setter
argument_list|,
name|int
name|defaultStyleValue
argument_list|,
name|bool
name|suppressDefault
argument_list|,
name|QTextStream
operator|&
name|str
argument_list|)
decl|const
decl_stmt|;
enum|enum
name|Properties
block|{
name|Margin
block|,
name|Spacing
block|,
name|NumProperties
block|}
enum|;
enum|enum
name|StateFlags
block|{
name|HasDefaultValue
init|=
literal|1
block|,
name|HasDefaultFunction
init|=
literal|2
block|}
enum|;
name|unsigned
name|m_state
index|[
name|NumProperties
index|]
decl_stmt|;
name|int
name|m_defaultValues
index|[
name|NumProperties
index|]
decl_stmt|;
name|QString
name|m_functions
index|[
name|NumProperties
index|]
decl_stmt|;
block|}
empty_stmt|;
comment|// layout defaults
name|LayoutDefaultHandler
name|m_LayoutDefaultHandler
decl_stmt|;
name|int
name|m_layoutMarginType
decl_stmt|;
name|QString
name|m_generatedClass
decl_stmt|;
name|QString
name|m_mainFormVarName
decl_stmt|;
name|bool
name|m_mainFormUsedInRetranslateUi
decl_stmt|;
name|QString
name|m_delayedInitialization
decl_stmt|;
name|QTextStream
name|m_delayedOut
decl_stmt|;
name|QString
name|m_refreshInitialization
decl_stmt|;
name|QTextStream
name|m_refreshOut
decl_stmt|;
name|QString
name|m_delayedActionInitialization
decl_stmt|;
name|QTextStream
name|m_actionOut
decl_stmt|;
specifier|const
name|bool
name|m_activateScripts
decl_stmt|;
name|bool
name|m_layoutWidget
decl_stmt|;
name|bool
name|m_firstThemeIcon
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
unit|}
comment|// namespace CPP
end_comment
begin_endif
unit|QT_END_NAMESPACE
endif|#
directive|endif
end_endif
begin_comment
comment|// CPPWRITEINITIALIZATION_H
end_comment
end_unit
