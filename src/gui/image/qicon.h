begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QICON_H
end_ifndef
begin_define
DECL|macro|QICON_H
define|#
directive|define
name|QICON_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qsize.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlist.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qpixmap.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QIconPrivate
name|class
name|QIconPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QIconEngine
name|class
name|QIconEngine
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QIcon
block|{
name|public
label|:
enum|enum
name|Mode
block|{
name|Normal
block|,
name|Disabled
block|,
name|Active
block|,
name|Selected
block|}
enum|;
enum|enum
name|State
block|{
name|On
block|,
name|Off
block|}
enum|;
name|QIcon
argument_list|()
expr_stmt|;
name|QIcon
argument_list|(
specifier|const
name|QPixmap
operator|&
name|pixmap
argument_list|)
expr_stmt|;
name|QIcon
argument_list|(
specifier|const
name|QIcon
operator|&
name|other
argument_list|)
expr_stmt|;
name|explicit
name|QIcon
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
function_decl|;
comment|// file or resource name
name|explicit
name|QIcon
parameter_list|(
name|QIconEngine
modifier|*
name|engine
parameter_list|)
function_decl|;
operator|~
name|QIcon
argument_list|()
expr_stmt|;
name|QIcon
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QIcon
operator|&
name|other
operator|)
decl_stmt|;
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
specifier|inline
name|QIcon
modifier|&
name|operator
init|=
operator|(
name|QIcon
operator|&&
name|other
operator|)
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
endif|#
directive|endif
specifier|inline
name|void
name|swap
parameter_list|(
name|QIcon
modifier|&
name|other
parameter_list|)
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
expr_stmt|;
block|}
name|operator
name|QVariant
argument_list|()
specifier|const
expr_stmt|;
name|QPixmap
name|pixmap
argument_list|(
specifier|const
name|QSize
operator|&
name|size
argument_list|,
name|Mode
name|mode
operator|=
name|Normal
argument_list|,
name|State
name|state
operator|=
name|Off
argument_list|)
decl|const
decl_stmt|;
specifier|inline
name|QPixmap
name|pixmap
argument_list|(
name|int
name|w
argument_list|,
name|int
name|h
argument_list|,
name|Mode
name|mode
operator|=
name|Normal
argument_list|,
name|State
name|state
operator|=
name|Off
argument_list|)
decl|const
block|{
return|return
name|pixmap
argument_list|(
name|QSize
argument_list|(
name|w
argument_list|,
name|h
argument_list|)
argument_list|,
name|mode
argument_list|,
name|state
argument_list|)
return|;
block|}
specifier|inline
name|QPixmap
name|pixmap
argument_list|(
name|int
name|extent
argument_list|,
name|Mode
name|mode
operator|=
name|Normal
argument_list|,
name|State
name|state
operator|=
name|Off
argument_list|)
decl|const
block|{
return|return
name|pixmap
argument_list|(
name|QSize
argument_list|(
name|extent
argument_list|,
name|extent
argument_list|)
argument_list|,
name|mode
argument_list|,
name|state
argument_list|)
return|;
block|}
name|QSize
name|actualSize
argument_list|(
specifier|const
name|QSize
operator|&
name|size
argument_list|,
name|Mode
name|mode
operator|=
name|Normal
argument_list|,
name|State
name|state
operator|=
name|Off
argument_list|)
decl|const
decl_stmt|;
name|QString
name|name
argument_list|()
specifier|const
expr_stmt|;
name|void
name|paint
argument_list|(
name|QPainter
operator|*
name|painter
argument_list|,
specifier|const
name|QRect
operator|&
name|rect
argument_list|,
name|Qt
operator|::
name|Alignment
name|alignment
operator|=
name|Qt
operator|::
name|AlignCenter
argument_list|,
name|Mode
name|mode
operator|=
name|Normal
argument_list|,
name|State
name|state
operator|=
name|Off
argument_list|)
decl|const
decl_stmt|;
specifier|inline
name|void
name|paint
argument_list|(
name|QPainter
operator|*
name|painter
argument_list|,
name|int
name|x
argument_list|,
name|int
name|y
argument_list|,
name|int
name|w
argument_list|,
name|int
name|h
argument_list|,
name|Qt
operator|::
name|Alignment
name|alignment
operator|=
name|Qt
operator|::
name|AlignCenter
argument_list|,
name|Mode
name|mode
operator|=
name|Normal
argument_list|,
name|State
name|state
operator|=
name|Off
argument_list|)
decl|const
block|{
name|paint
argument_list|(
name|painter
argument_list|,
name|QRect
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|w
argument_list|,
name|h
argument_list|)
argument_list|,
name|alignment
argument_list|,
name|mode
argument_list|,
name|state
argument_list|)
expr_stmt|;
block|}
name|bool
name|isNull
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isDetached
argument_list|()
specifier|const
expr_stmt|;
name|void
name|detach
parameter_list|()
function_decl|;
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|0
argument_list|)
name|QT_DEPRECATED
specifier|inline
name|int
name|serialNumber
argument_list|()
specifier|const
block|{
return|return
name|cacheKey
argument_list|()
operator|>>
literal|32
return|;
block|}
endif|#
directive|endif
name|qint64
name|cacheKey
argument_list|()
specifier|const
expr_stmt|;
name|void
name|addPixmap
parameter_list|(
specifier|const
name|QPixmap
modifier|&
name|pixmap
parameter_list|,
name|Mode
name|mode
init|=
name|Normal
parameter_list|,
name|State
name|state
init|=
name|Off
parameter_list|)
function_decl|;
name|void
name|addFile
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|,
specifier|const
name|QSize
modifier|&
name|size
init|=
name|QSize
argument_list|()
parameter_list|,
name|Mode
name|mode
init|=
name|Normal
parameter_list|,
name|State
name|state
init|=
name|Off
parameter_list|)
function_decl|;
name|QList
operator|<
name|QSize
operator|>
name|availableSizes
argument_list|(
argument|Mode mode = Normal
argument_list|,
argument|State state = Off
argument_list|)
specifier|const
expr_stmt|;
specifier|static
name|QIcon
name|fromTheme
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
specifier|const
name|QIcon
modifier|&
name|fallback
init|=
name|QIcon
argument_list|()
parameter_list|)
function_decl|;
specifier|static
name|bool
name|hasThemeIcon
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
specifier|static
name|QStringList
name|themeSearchPaths
parameter_list|()
function_decl|;
specifier|static
name|void
name|setThemeSearchPaths
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|searchpath
parameter_list|)
function_decl|;
specifier|static
name|QString
name|themeName
parameter_list|()
function_decl|;
specifier|static
name|void
name|setThemeName
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|)
function_decl|;
name|Q_DUMMY_COMPARISON_OPERATOR
argument_list|(
argument|QIcon
argument_list|)
name|private
label|:
name|QIconPrivate
modifier|*
name|d
decl_stmt|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_DATASTREAM
argument_list|)
name|friend
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
operator|,
specifier|const
name|QIcon
operator|&
operator|)
expr_stmt|;
name|friend
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
operator|,
name|QIcon
operator|&
operator|)
expr_stmt|;
endif|#
directive|endif
name|public
label|:
typedef|typedef
name|QIconPrivate
modifier|*
name|DataPtr
typedef|;
specifier|inline
name|DataPtr
modifier|&
name|data_ptr
parameter_list|()
block|{
return|return
name|d
return|;
block|}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|Q_DECLARE_SHARED
argument_list|(
argument|QIcon
argument_list|)
end_macro
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_DATASTREAM
argument_list|)
end_if
begin_expr_stmt
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
operator|,
specifier|const
name|QIcon
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|operator
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
operator|,
name|QIcon
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_expr_stmt
name|Q_GUI_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
name|dbg
operator|,
specifier|const
name|QIcon
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QICON_H
end_comment
end_unit
