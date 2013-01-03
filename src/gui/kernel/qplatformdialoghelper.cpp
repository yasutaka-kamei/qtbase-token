begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qplatformdialoghelper.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QVariant>
end_include
begin_include
include|#
directive|include
file|<QtCore/QSharedData>
end_include
begin_include
include|#
directive|include
file|<QtCore/QSettings>
end_include
begin_include
include|#
directive|include
file|<QtCore/QHash>
end_include
begin_include
include|#
directive|include
file|<QtCore/QUrl>
end_include
begin_include
include|#
directive|include
file|<QtGui/QColor>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*!     \class QPlatformDialogHelper     \since 5.0     \internal     \ingroup qpa      \brief The QPlatformDialogHelper class allows for platform-specific customization of dialogs.  */
comment|/*!     \enum QPlatformDialogHelper::StyleHint      This enum type specifies platform-specific style hints.      \value SnapToDefaultButton Snap the mouse to the center of the default                                button. There is corresponding system                                setting on Windows.      \sa styleHint() */
DECL|function|QPlatformDialogHelper
name|QPlatformDialogHelper
operator|::
name|QPlatformDialogHelper
parameter_list|()
block|{ }
end_function
begin_destructor
DECL|function|~QPlatformDialogHelper
name|QPlatformDialogHelper
operator|::
name|~
name|QPlatformDialogHelper
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|styleHint
name|QVariant
name|QPlatformDialogHelper
operator|::
name|styleHint
parameter_list|(
name|StyleHint
name|hint
parameter_list|)
specifier|const
block|{
return|return
name|QPlatformDialogHelper
operator|::
name|defaultStyleHint
argument_list|(
name|hint
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|defaultStyleHint
name|QVariant
name|QPlatformDialogHelper
operator|::
name|defaultStyleHint
parameter_list|(
name|QPlatformDialogHelper
operator|::
name|StyleHint
name|hint
parameter_list|)
block|{
switch|switch
condition|(
name|hint
condition|)
block|{
case|case
name|QPlatformDialogHelper
operator|::
name|SnapToDefaultButton
case|:
return|return
name|QVariant
argument_list|(
literal|false
argument_list|)
return|;
block|}
return|return
name|QVariant
argument_list|()
return|;
block|}
end_function
begin_comment
comment|// Font dialog
end_comment
begin_class
DECL|class|QFontDialogOptionsPrivate
class|class
name|QFontDialogOptionsPrivate
super|:
specifier|public
name|QSharedData
block|{
public|public:
DECL|function|QFontDialogOptionsPrivate
name|QFontDialogOptionsPrivate
parameter_list|()
member_init_list|:
name|options
argument_list|(
literal|0
argument_list|)
block|{}
DECL|member|options
name|QFontDialogOptions
operator|::
name|FontDialogOptions
name|options
decl_stmt|;
DECL|member|windowTitle
name|QString
name|windowTitle
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|QFontDialogOptions
name|QFontDialogOptions
operator|::
name|QFontDialogOptions
parameter_list|()
member_init_list|:
name|d
argument_list|(
operator|new
name|QFontDialogOptionsPrivate
argument_list|)
block|{ }
end_constructor
begin_constructor
DECL|function|QFontDialogOptions
name|QFontDialogOptions
operator|::
name|QFontDialogOptions
parameter_list|(
specifier|const
name|QFontDialogOptions
modifier|&
name|rhs
parameter_list|)
member_init_list|:
name|d
argument_list|(
name|rhs
operator|.
name|d
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|operator =
name|QFontDialogOptions
modifier|&
name|QFontDialogOptions
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|QFontDialogOptions
modifier|&
name|rhs
parameter_list|)
block|{
if|if
condition|(
name|this
operator|!=
operator|&
name|rhs
condition|)
name|d
operator|=
name|rhs
operator|.
name|d
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_function
begin_destructor
DECL|function|~QFontDialogOptions
name|QFontDialogOptions
operator|::
name|~
name|QFontDialogOptions
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|windowTitle
name|QString
name|QFontDialogOptions
operator|::
name|windowTitle
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|windowTitle
return|;
block|}
end_function
begin_function
DECL|function|setWindowTitle
name|void
name|QFontDialogOptions
operator|::
name|setWindowTitle
parameter_list|(
specifier|const
name|QString
modifier|&
name|title
parameter_list|)
block|{
name|d
operator|->
name|windowTitle
operator|=
name|title
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setOption
name|void
name|QFontDialogOptions
operator|::
name|setOption
parameter_list|(
name|QFontDialogOptions
operator|::
name|FontDialogOption
name|option
parameter_list|,
name|bool
name|on
parameter_list|)
block|{
if|if
condition|(
operator|!
operator|(
name|d
operator|->
name|options
operator|&
name|option
operator|)
operator|!=
operator|!
name|on
condition|)
name|setOptions
argument_list|(
name|d
operator|->
name|options
operator|^
name|option
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testOption
name|bool
name|QFontDialogOptions
operator|::
name|testOption
parameter_list|(
name|QFontDialogOptions
operator|::
name|FontDialogOption
name|option
parameter_list|)
specifier|const
block|{
return|return
name|d
operator|->
name|options
operator|&
name|option
return|;
block|}
end_function
begin_function
DECL|function|setOptions
name|void
name|QFontDialogOptions
operator|::
name|setOptions
parameter_list|(
name|FontDialogOptions
name|options
parameter_list|)
block|{
if|if
condition|(
name|options
operator|!=
name|d
operator|->
name|options
condition|)
name|d
operator|->
name|options
operator|=
name|options
expr_stmt|;
block|}
end_function
begin_function
DECL|function|options
name|QFontDialogOptions
operator|::
name|FontDialogOptions
name|QFontDialogOptions
operator|::
name|options
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|options
return|;
block|}
end_function
begin_comment
comment|/*!     \class QPlatformFontDialogHelper     \since 5.0     \internal     \ingroup qpa      \brief The QPlatformFontDialogHelper class allows for platform-specific customization of font dialogs.  */
end_comment
begin_function
DECL|function|options
specifier|const
name|QSharedPointer
argument_list|<
name|QFontDialogOptions
argument_list|>
modifier|&
name|QPlatformFontDialogHelper
operator|::
name|options
parameter_list|()
specifier|const
block|{
return|return
name|m_options
return|;
block|}
end_function
begin_function
DECL|function|setOptions
name|void
name|QPlatformFontDialogHelper
operator|::
name|setOptions
parameter_list|(
specifier|const
name|QSharedPointer
argument_list|<
name|QFontDialogOptions
argument_list|>
modifier|&
name|options
parameter_list|)
block|{
name|m_options
operator|=
name|options
expr_stmt|;
block|}
end_function
begin_comment
comment|// Color dialog
end_comment
begin_class
DECL|class|QColorDialogStaticData
class|class
name|QColorDialogStaticData
block|{
public|public:
DECL|enumerator|CustomColorCount
DECL|enumerator|StandardColorCount
enum|enum
block|{
name|CustomColorCount
init|=
literal|16
block|,
name|StandardColorCount
init|=
literal|6
operator|*
literal|8
block|}
enum|;
name|QColorDialogStaticData
parameter_list|()
constructor_decl|;
specifier|inline
name|void
name|readSettings
parameter_list|()
function_decl|;
specifier|inline
name|void
name|writeSettings
parameter_list|()
specifier|const
function_decl|;
DECL|member|customRgb
name|QRgb
name|customRgb
index|[
name|CustomColorCount
index|]
decl_stmt|;
DECL|member|standardRgb
name|QRgb
name|standardRgb
index|[
name|StandardColorCount
index|]
decl_stmt|;
DECL|member|customSet
name|bool
name|customSet
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|QColorDialogStaticData
name|QColorDialogStaticData
operator|::
name|QColorDialogStaticData
parameter_list|()
member_init_list|:
name|customSet
argument_list|(
literal|false
argument_list|)
block|{
name|int
name|i
init|=
literal|0
decl_stmt|;
for|for
control|(
name|int
name|g
init|=
literal|0
init|;
name|g
operator|<
literal|4
condition|;
operator|++
name|g
control|)
for|for
control|(
name|int
name|r
init|=
literal|0
init|;
name|r
operator|<
literal|4
condition|;
operator|++
name|r
control|)
for|for
control|(
name|int
name|b
init|=
literal|0
init|;
name|b
operator|<
literal|3
condition|;
operator|++
name|b
control|)
name|standardRgb
index|[
name|i
operator|++
index|]
operator|=
name|qRgb
argument_list|(
name|r
operator|*
literal|255
operator|/
literal|3
argument_list|,
name|g
operator|*
literal|255
operator|/
literal|3
argument_list|,
name|b
operator|*
literal|255
operator|/
literal|2
argument_list|)
expr_stmt|;
name|qFill
argument_list|(
name|customRgb
argument_list|,
name|customRgb
operator|+
name|CustomColorCount
argument_list|,
literal|0xffffffff
argument_list|)
expr_stmt|;
name|readSettings
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|readSettings
name|void
name|QColorDialogStaticData
operator|::
name|readSettings
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|QT_NO_SETTINGS
specifier|const
name|QSettings
name|settings
argument_list|(
name|QSettings
operator|::
name|UserScope
argument_list|,
name|QStringLiteral
argument_list|(
literal|"QtProject"
argument_list|)
argument_list|)
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
name|int
argument_list|(
name|CustomColorCount
argument_list|)
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|QVariant
name|v
init|=
name|settings
operator|.
name|value
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Qt/customColors/"
argument_list|)
operator|+
name|QString
operator|::
name|number
argument_list|(
name|i
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|v
operator|.
name|isValid
argument_list|()
condition|)
name|customRgb
index|[
name|i
index|]
operator|=
name|v
operator|.
name|toUInt
argument_list|()
expr_stmt|;
block|}
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|writeSettings
name|void
name|QColorDialogStaticData
operator|::
name|writeSettings
parameter_list|()
specifier|const
block|{
ifndef|#
directive|ifndef
name|QT_NO_SETTINGS
if|if
condition|(
operator|!
name|customSet
condition|)
block|{
name|QSettings
name|settings
argument_list|(
name|QSettings
operator|::
name|UserScope
argument_list|,
name|QStringLiteral
argument_list|(
literal|"QtProject"
argument_list|)
argument_list|)
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
name|int
argument_list|(
name|CustomColorCount
argument_list|)
condition|;
operator|++
name|i
control|)
name|settings
operator|.
name|setValue
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Qt/customColors/"
argument_list|)
operator|+
name|QString
operator|::
name|number
argument_list|(
name|i
argument_list|)
argument_list|,
name|customRgb
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
block|}
end_function
begin_macro
name|Q_GLOBAL_STATIC
argument_list|(
argument|QColorDialogStaticData
argument_list|,
argument|qColorDialogStaticData
argument_list|)
end_macro
begin_class
DECL|class|QColorDialogOptionsPrivate
class|class
name|QColorDialogOptionsPrivate
super|:
specifier|public
name|QSharedData
block|{
public|public:
DECL|function|QColorDialogOptionsPrivate
name|QColorDialogOptionsPrivate
parameter_list|()
member_init_list|:
name|options
argument_list|(
literal|0
argument_list|)
block|{}
comment|// Write out settings around destruction of dialogs
DECL|function|~QColorDialogOptionsPrivate
name|~
name|QColorDialogOptionsPrivate
parameter_list|()
block|{
name|qColorDialogStaticData
argument_list|()
operator|->
name|writeSettings
argument_list|()
expr_stmt|;
block|}
DECL|member|options
name|QColorDialogOptions
operator|::
name|ColorDialogOptions
name|options
decl_stmt|;
DECL|member|windowTitle
name|QString
name|windowTitle
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|QColorDialogOptions
name|QColorDialogOptions
operator|::
name|QColorDialogOptions
parameter_list|()
member_init_list|:
name|d
argument_list|(
operator|new
name|QColorDialogOptionsPrivate
argument_list|)
block|{ }
end_constructor
begin_constructor
DECL|function|QColorDialogOptions
name|QColorDialogOptions
operator|::
name|QColorDialogOptions
parameter_list|(
specifier|const
name|QColorDialogOptions
modifier|&
name|rhs
parameter_list|)
member_init_list|:
name|d
argument_list|(
name|rhs
operator|.
name|d
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|operator =
name|QColorDialogOptions
modifier|&
name|QColorDialogOptions
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|QColorDialogOptions
modifier|&
name|rhs
parameter_list|)
block|{
if|if
condition|(
name|this
operator|!=
operator|&
name|rhs
condition|)
name|d
operator|=
name|rhs
operator|.
name|d
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_function
begin_destructor
DECL|function|~QColorDialogOptions
name|QColorDialogOptions
operator|::
name|~
name|QColorDialogOptions
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|windowTitle
name|QString
name|QColorDialogOptions
operator|::
name|windowTitle
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|windowTitle
return|;
block|}
end_function
begin_function
DECL|function|setWindowTitle
name|void
name|QColorDialogOptions
operator|::
name|setWindowTitle
parameter_list|(
specifier|const
name|QString
modifier|&
name|title
parameter_list|)
block|{
name|d
operator|->
name|windowTitle
operator|=
name|title
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setOption
name|void
name|QColorDialogOptions
operator|::
name|setOption
parameter_list|(
name|QColorDialogOptions
operator|::
name|ColorDialogOption
name|option
parameter_list|,
name|bool
name|on
parameter_list|)
block|{
if|if
condition|(
operator|!
operator|(
name|d
operator|->
name|options
operator|&
name|option
operator|)
operator|!=
operator|!
name|on
condition|)
name|setOptions
argument_list|(
name|d
operator|->
name|options
operator|^
name|option
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testOption
name|bool
name|QColorDialogOptions
operator|::
name|testOption
parameter_list|(
name|QColorDialogOptions
operator|::
name|ColorDialogOption
name|option
parameter_list|)
specifier|const
block|{
return|return
name|d
operator|->
name|options
operator|&
name|option
return|;
block|}
end_function
begin_function
DECL|function|setOptions
name|void
name|QColorDialogOptions
operator|::
name|setOptions
parameter_list|(
name|ColorDialogOptions
name|options
parameter_list|)
block|{
if|if
condition|(
name|options
operator|!=
name|d
operator|->
name|options
condition|)
name|d
operator|->
name|options
operator|=
name|options
expr_stmt|;
block|}
end_function
begin_function
DECL|function|options
name|QColorDialogOptions
operator|::
name|ColorDialogOptions
name|QColorDialogOptions
operator|::
name|options
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|options
return|;
block|}
end_function
begin_function
DECL|function|customColorCount
name|int
name|QColorDialogOptions
operator|::
name|customColorCount
parameter_list|()
block|{
return|return
name|QColorDialogStaticData
operator|::
name|CustomColorCount
return|;
block|}
end_function
begin_function
DECL|function|customColor
name|QRgb
name|QColorDialogOptions
operator|::
name|customColor
parameter_list|(
name|int
name|index
parameter_list|)
block|{
if|if
condition|(
name|uint
argument_list|(
name|index
argument_list|)
operator|>=
name|uint
argument_list|(
name|QColorDialogStaticData
operator|::
name|CustomColorCount
argument_list|)
condition|)
return|return
name|qRgb
argument_list|(
literal|255
argument_list|,
literal|255
argument_list|,
literal|255
argument_list|)
return|;
return|return
name|qColorDialogStaticData
argument_list|()
operator|->
name|customRgb
index|[
name|index
index|]
return|;
block|}
end_function
begin_function
DECL|function|customColors
name|QRgb
modifier|*
name|QColorDialogOptions
operator|::
name|customColors
parameter_list|()
block|{
return|return
name|qColorDialogStaticData
argument_list|()
operator|->
name|customRgb
return|;
block|}
end_function
begin_function
DECL|function|setCustomColor
name|void
name|QColorDialogOptions
operator|::
name|setCustomColor
parameter_list|(
name|int
name|index
parameter_list|,
name|QRgb
name|color
parameter_list|)
block|{
if|if
condition|(
name|uint
argument_list|(
name|index
argument_list|)
operator|>=
name|uint
argument_list|(
name|QColorDialogStaticData
operator|::
name|CustomColorCount
argument_list|)
condition|)
return|return;
name|qColorDialogStaticData
argument_list|()
operator|->
name|customSet
operator|=
literal|true
expr_stmt|;
name|qColorDialogStaticData
argument_list|()
operator|->
name|customRgb
index|[
name|index
index|]
operator|=
name|color
expr_stmt|;
block|}
end_function
begin_function
DECL|function|standardColors
name|QRgb
modifier|*
name|QColorDialogOptions
operator|::
name|standardColors
parameter_list|()
block|{
return|return
name|qColorDialogStaticData
argument_list|()
operator|->
name|standardRgb
return|;
block|}
end_function
begin_function
DECL|function|standardColor
name|QRgb
name|QColorDialogOptions
operator|::
name|standardColor
parameter_list|(
name|int
name|index
parameter_list|)
block|{
if|if
condition|(
name|uint
argument_list|(
name|index
argument_list|)
operator|>=
name|uint
argument_list|(
name|QColorDialogStaticData
operator|::
name|StandardColorCount
argument_list|)
condition|)
return|return
name|qRgb
argument_list|(
literal|255
argument_list|,
literal|255
argument_list|,
literal|255
argument_list|)
return|;
return|return
name|qColorDialogStaticData
argument_list|()
operator|->
name|standardRgb
index|[
name|index
index|]
return|;
block|}
end_function
begin_function
DECL|function|setStandardColor
name|void
name|QColorDialogOptions
operator|::
name|setStandardColor
parameter_list|(
name|int
name|index
parameter_list|,
name|QRgb
name|color
parameter_list|)
block|{
if|if
condition|(
name|uint
argument_list|(
name|index
argument_list|)
operator|>=
name|uint
argument_list|(
name|QColorDialogStaticData
operator|::
name|StandardColorCount
argument_list|)
condition|)
return|return;
name|qColorDialogStaticData
argument_list|()
operator|->
name|standardRgb
index|[
name|index
index|]
operator|=
name|color
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \class QPlatformColorDialogHelper     \since 5.0     \internal     \ingroup qpa      \brief The QPlatformColorDialogHelper class allows for platform-specific customization of color dialogs.  */
end_comment
begin_function
DECL|function|options
specifier|const
name|QSharedPointer
argument_list|<
name|QColorDialogOptions
argument_list|>
modifier|&
name|QPlatformColorDialogHelper
operator|::
name|options
parameter_list|()
specifier|const
block|{
return|return
name|m_options
return|;
block|}
end_function
begin_function
DECL|function|setOptions
name|void
name|QPlatformColorDialogHelper
operator|::
name|setOptions
parameter_list|(
specifier|const
name|QSharedPointer
argument_list|<
name|QColorDialogOptions
argument_list|>
modifier|&
name|options
parameter_list|)
block|{
name|m_options
operator|=
name|options
expr_stmt|;
block|}
end_function
begin_comment
comment|// File dialog
end_comment
begin_class
DECL|class|QFileDialogOptionsPrivate
class|class
name|QFileDialogOptionsPrivate
super|:
specifier|public
name|QSharedData
block|{
public|public:
DECL|function|QFileDialogOptionsPrivate
name|QFileDialogOptionsPrivate
parameter_list|()
member_init_list|:
name|options
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|viewMode
argument_list|(
name|QFileDialogOptions
operator|::
name|Detail
argument_list|)
member_init_list|,
name|fileMode
argument_list|(
name|QFileDialogOptions
operator|::
name|AnyFile
argument_list|)
member_init_list|,
name|acceptMode
argument_list|(
name|QFileDialogOptions
operator|::
name|AcceptOpen
argument_list|)
member_init_list|,
name|filters
argument_list|(
name|QDir
operator|::
name|AllEntries
operator||
name|QDir
operator|::
name|NoDotAndDotDot
operator||
name|QDir
operator|::
name|AllDirs
argument_list|)
block|{}
DECL|member|options
name|QFileDialogOptions
operator|::
name|FileDialogOptions
name|options
decl_stmt|;
DECL|member|windowTitle
name|QString
name|windowTitle
decl_stmt|;
DECL|member|viewMode
name|QFileDialogOptions
operator|::
name|ViewMode
name|viewMode
decl_stmt|;
DECL|member|fileMode
name|QFileDialogOptions
operator|::
name|FileMode
name|fileMode
decl_stmt|;
DECL|member|acceptMode
name|QFileDialogOptions
operator|::
name|AcceptMode
name|acceptMode
decl_stmt|;
DECL|member|labels
name|QString
name|labels
index|[
name|QFileDialogOptions
operator|::
name|DialogLabelCount
index|]
decl_stmt|;
DECL|member|filters
name|QDir
operator|::
name|Filters
name|filters
decl_stmt|;
DECL|member|sidebarUrls
name|QList
argument_list|<
name|QUrl
argument_list|>
name|sidebarUrls
decl_stmt|;
DECL|member|nameFilters
name|QStringList
name|nameFilters
decl_stmt|;
DECL|member|defaultSuffix
name|QString
name|defaultSuffix
decl_stmt|;
DECL|member|history
name|QStringList
name|history
decl_stmt|;
DECL|member|initialDirectory
name|QString
name|initialDirectory
decl_stmt|;
DECL|member|initiallySelectedNameFilter
name|QString
name|initiallySelectedNameFilter
decl_stmt|;
DECL|member|initiallySelectedFiles
name|QStringList
name|initiallySelectedFiles
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|QFileDialogOptions
name|QFileDialogOptions
operator|::
name|QFileDialogOptions
parameter_list|()
member_init_list|:
name|d
argument_list|(
operator|new
name|QFileDialogOptionsPrivate
argument_list|)
block|{ }
end_constructor
begin_constructor
DECL|function|QFileDialogOptions
name|QFileDialogOptions
operator|::
name|QFileDialogOptions
parameter_list|(
specifier|const
name|QFileDialogOptions
modifier|&
name|rhs
parameter_list|)
member_init_list|:
name|d
argument_list|(
name|rhs
operator|.
name|d
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|operator =
name|QFileDialogOptions
modifier|&
name|QFileDialogOptions
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|QFileDialogOptions
modifier|&
name|rhs
parameter_list|)
block|{
if|if
condition|(
name|this
operator|!=
operator|&
name|rhs
condition|)
name|d
operator|=
name|rhs
operator|.
name|d
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_function
begin_destructor
DECL|function|~QFileDialogOptions
name|QFileDialogOptions
operator|::
name|~
name|QFileDialogOptions
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|windowTitle
name|QString
name|QFileDialogOptions
operator|::
name|windowTitle
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|windowTitle
return|;
block|}
end_function
begin_function
DECL|function|setWindowTitle
name|void
name|QFileDialogOptions
operator|::
name|setWindowTitle
parameter_list|(
specifier|const
name|QString
modifier|&
name|title
parameter_list|)
block|{
name|d
operator|->
name|windowTitle
operator|=
name|title
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setOption
name|void
name|QFileDialogOptions
operator|::
name|setOption
parameter_list|(
name|QFileDialogOptions
operator|::
name|FileDialogOption
name|option
parameter_list|,
name|bool
name|on
parameter_list|)
block|{
if|if
condition|(
operator|!
operator|(
name|d
operator|->
name|options
operator|&
name|option
operator|)
operator|!=
operator|!
name|on
condition|)
name|setOptions
argument_list|(
name|d
operator|->
name|options
operator|^
name|option
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testOption
name|bool
name|QFileDialogOptions
operator|::
name|testOption
parameter_list|(
name|QFileDialogOptions
operator|::
name|FileDialogOption
name|option
parameter_list|)
specifier|const
block|{
return|return
name|d
operator|->
name|options
operator|&
name|option
return|;
block|}
end_function
begin_function
DECL|function|setOptions
name|void
name|QFileDialogOptions
operator|::
name|setOptions
parameter_list|(
name|FileDialogOptions
name|options
parameter_list|)
block|{
if|if
condition|(
name|options
operator|!=
name|d
operator|->
name|options
condition|)
name|d
operator|->
name|options
operator|=
name|options
expr_stmt|;
block|}
end_function
begin_function
DECL|function|options
name|QFileDialogOptions
operator|::
name|FileDialogOptions
name|QFileDialogOptions
operator|::
name|options
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|options
return|;
block|}
end_function
begin_function
DECL|function|filter
name|QDir
operator|::
name|Filters
name|QFileDialogOptions
operator|::
name|filter
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|filters
return|;
block|}
end_function
begin_function
DECL|function|setFilter
name|void
name|QFileDialogOptions
operator|::
name|setFilter
parameter_list|(
name|QDir
operator|::
name|Filters
name|filters
parameter_list|)
block|{
name|d
operator|->
name|filters
operator|=
name|filters
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setViewMode
name|void
name|QFileDialogOptions
operator|::
name|setViewMode
parameter_list|(
name|QFileDialogOptions
operator|::
name|ViewMode
name|mode
parameter_list|)
block|{
name|d
operator|->
name|viewMode
operator|=
name|mode
expr_stmt|;
block|}
end_function
begin_function
DECL|function|viewMode
name|QFileDialogOptions
operator|::
name|ViewMode
name|QFileDialogOptions
operator|::
name|viewMode
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|viewMode
return|;
block|}
end_function
begin_function
DECL|function|setFileMode
name|void
name|QFileDialogOptions
operator|::
name|setFileMode
parameter_list|(
name|QFileDialogOptions
operator|::
name|FileMode
name|mode
parameter_list|)
block|{
name|d
operator|->
name|fileMode
operator|=
name|mode
expr_stmt|;
block|}
end_function
begin_function
DECL|function|fileMode
name|QFileDialogOptions
operator|::
name|FileMode
name|QFileDialogOptions
operator|::
name|fileMode
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|fileMode
return|;
block|}
end_function
begin_function
DECL|function|setAcceptMode
name|void
name|QFileDialogOptions
operator|::
name|setAcceptMode
parameter_list|(
name|QFileDialogOptions
operator|::
name|AcceptMode
name|mode
parameter_list|)
block|{
name|d
operator|->
name|acceptMode
operator|=
name|mode
expr_stmt|;
block|}
end_function
begin_function
DECL|function|acceptMode
name|QFileDialogOptions
operator|::
name|AcceptMode
name|QFileDialogOptions
operator|::
name|acceptMode
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|acceptMode
return|;
block|}
end_function
begin_function
DECL|function|setSidebarUrls
name|void
name|QFileDialogOptions
operator|::
name|setSidebarUrls
parameter_list|(
specifier|const
name|QList
argument_list|<
name|QUrl
argument_list|>
modifier|&
name|urls
parameter_list|)
block|{
name|d
operator|->
name|sidebarUrls
operator|=
name|urls
expr_stmt|;
block|}
end_function
begin_function
DECL|function|sidebarUrls
name|QList
argument_list|<
name|QUrl
argument_list|>
name|QFileDialogOptions
operator|::
name|sidebarUrls
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|sidebarUrls
return|;
block|}
end_function
begin_function
DECL|function|setNameFilters
name|void
name|QFileDialogOptions
operator|::
name|setNameFilters
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|filters
parameter_list|)
block|{
name|d
operator|->
name|nameFilters
operator|=
name|filters
expr_stmt|;
block|}
end_function
begin_function
DECL|function|nameFilters
name|QStringList
name|QFileDialogOptions
operator|::
name|nameFilters
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|nameFilters
return|;
block|}
end_function
begin_function
DECL|function|setDefaultSuffix
name|void
name|QFileDialogOptions
operator|::
name|setDefaultSuffix
parameter_list|(
specifier|const
name|QString
modifier|&
name|suffix
parameter_list|)
block|{
name|d
operator|->
name|defaultSuffix
operator|=
name|suffix
expr_stmt|;
block|}
end_function
begin_function
DECL|function|defaultSuffix
name|QString
name|QFileDialogOptions
operator|::
name|defaultSuffix
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|defaultSuffix
return|;
block|}
end_function
begin_function
DECL|function|setHistory
name|void
name|QFileDialogOptions
operator|::
name|setHistory
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|paths
parameter_list|)
block|{
name|d
operator|->
name|history
operator|=
name|paths
expr_stmt|;
block|}
end_function
begin_function
DECL|function|history
name|QStringList
name|QFileDialogOptions
operator|::
name|history
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|history
return|;
block|}
end_function
begin_function
DECL|function|setLabelText
name|void
name|QFileDialogOptions
operator|::
name|setLabelText
parameter_list|(
name|QFileDialogOptions
operator|::
name|DialogLabel
name|label
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
block|{
if|if
condition|(
name|label
operator|>=
literal|0
operator|&&
name|label
operator|<
name|DialogLabelCount
condition|)
name|d
operator|->
name|labels
index|[
name|label
index|]
operator|=
name|text
expr_stmt|;
block|}
end_function
begin_function
DECL|function|labelText
name|QString
name|QFileDialogOptions
operator|::
name|labelText
parameter_list|(
name|QFileDialogOptions
operator|::
name|DialogLabel
name|label
parameter_list|)
specifier|const
block|{
return|return
operator|(
name|label
operator|>=
literal|0
operator|&&
name|label
operator|<
name|DialogLabelCount
operator|)
condition|?
name|d
operator|->
name|labels
index|[
name|label
index|]
else|:
name|QString
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|isLabelExplicitlySet
name|bool
name|QFileDialogOptions
operator|::
name|isLabelExplicitlySet
parameter_list|(
name|DialogLabel
name|label
parameter_list|)
block|{
return|return
name|label
operator|>=
literal|0
operator|&&
name|label
operator|<
name|DialogLabelCount
operator|&&
operator|!
name|d
operator|->
name|labels
index|[
name|label
index|]
operator|.
name|isEmpty
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|initialDirectory
name|QString
name|QFileDialogOptions
operator|::
name|initialDirectory
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|initialDirectory
return|;
block|}
end_function
begin_function
DECL|function|setInitialDirectory
name|void
name|QFileDialogOptions
operator|::
name|setInitialDirectory
parameter_list|(
specifier|const
name|QString
modifier|&
name|directory
parameter_list|)
block|{
name|d
operator|->
name|initialDirectory
operator|=
name|directory
expr_stmt|;
block|}
end_function
begin_function
DECL|function|initiallySelectedNameFilter
name|QString
name|QFileDialogOptions
operator|::
name|initiallySelectedNameFilter
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|initiallySelectedNameFilter
return|;
block|}
end_function
begin_function
DECL|function|setInitiallySelectedNameFilter
name|void
name|QFileDialogOptions
operator|::
name|setInitiallySelectedNameFilter
parameter_list|(
specifier|const
name|QString
modifier|&
name|filter
parameter_list|)
block|{
name|d
operator|->
name|initiallySelectedNameFilter
operator|=
name|filter
expr_stmt|;
block|}
end_function
begin_function
DECL|function|initiallySelectedFiles
name|QStringList
name|QFileDialogOptions
operator|::
name|initiallySelectedFiles
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|initiallySelectedFiles
return|;
block|}
end_function
begin_function
DECL|function|setInitiallySelectedFiles
name|void
name|QFileDialogOptions
operator|::
name|setInitiallySelectedFiles
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|files
parameter_list|)
block|{
name|d
operator|->
name|initiallySelectedFiles
operator|=
name|files
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \class QPlatformFileDialogHelper     \since 5.0     \internal     \ingroup qpa      \brief The QPlatformFileDialogHelper class allows for platform-specific customization of file dialogs.  */
end_comment
begin_function
DECL|function|options
specifier|const
name|QSharedPointer
argument_list|<
name|QFileDialogOptions
argument_list|>
modifier|&
name|QPlatformFileDialogHelper
operator|::
name|options
parameter_list|()
specifier|const
block|{
return|return
name|m_options
return|;
block|}
end_function
begin_function
DECL|function|setOptions
name|void
name|QPlatformFileDialogHelper
operator|::
name|setOptions
parameter_list|(
specifier|const
name|QSharedPointer
argument_list|<
name|QFileDialogOptions
argument_list|>
modifier|&
name|options
parameter_list|)
block|{
name|m_options
operator|=
name|options
expr_stmt|;
block|}
end_function
begin_decl_stmt
DECL|member|filterRegExp
specifier|const
name|char
modifier|*
name|QPlatformFileDialogHelper
operator|::
name|filterRegExp
init|=
literal|"^(.*)\\(([a-zA-Z0-9_.*? +;#\\-\\[\\]@\\{\\}/!<>\\$%&=^~:\\|]*)\\)$"
decl_stmt|;
end_decl_stmt
begin_comment
comment|// Makes a list of filters from a normal filter string "Image Files (*.png *.jpg)"
end_comment
begin_function
DECL|function|cleanFilterList
name|QStringList
name|QPlatformFileDialogHelper
operator|::
name|cleanFilterList
parameter_list|(
specifier|const
name|QString
modifier|&
name|filter
parameter_list|)
block|{
name|QRegExp
name|regexp
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|filterRegExp
argument_list|)
argument_list|)
decl_stmt|;
name|QString
name|f
init|=
name|filter
decl_stmt|;
name|int
name|i
init|=
name|regexp
operator|.
name|indexIn
argument_list|(
name|f
argument_list|)
decl_stmt|;
if|if
condition|(
name|i
operator|>=
literal|0
condition|)
name|f
operator|=
name|regexp
operator|.
name|cap
argument_list|(
literal|2
argument_list|)
expr_stmt|;
return|return
name|f
operator|.
name|split
argument_list|(
name|QLatin1Char
argument_list|(
literal|' '
argument_list|)
argument_list|,
name|QString
operator|::
name|SkipEmptyParts
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
