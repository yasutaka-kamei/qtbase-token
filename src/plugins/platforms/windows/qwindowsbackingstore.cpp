begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwindowsbackingstore.h"
end_include
begin_include
include|#
directive|include
file|"qwindowswindow.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsnativeimage.h"
end_include
begin_include
include|#
directive|include
file|"qwindowscontext.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QWindow>
end_include
begin_include
include|#
directive|include
file|<QtGui/QPainter>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QWindowsBackingStore     \brief Backing store for windows.     \internal     \ingroup qt-lighthouse-win */
end_comment
begin_constructor
DECL|function|QWindowsBackingStore
name|QWindowsBackingStore
operator|::
name|QWindowsBackingStore
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
member_init_list|:
name|QPlatformBackingStore
argument_list|(
name|window
argument_list|)
block|{
if|if
condition|(
name|QWindowsContext
operator|::
name|verboseBackingStore
condition|)
name|qDebug
argument_list|()
operator|<<
name|__FUNCTION__
operator|<<
name|this
operator|<<
name|window
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QWindowsBackingStore
name|QWindowsBackingStore
operator|::
name|~
name|QWindowsBackingStore
parameter_list|()
block|{
if|if
condition|(
name|QWindowsContext
operator|::
name|verboseBackingStore
condition|)
name|qDebug
argument_list|()
operator|<<
name|__FUNCTION__
operator|<<
name|this
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|paintDevice
name|QPaintDevice
modifier|*
name|QWindowsBackingStore
operator|::
name|paintDevice
parameter_list|()
block|{
name|Q_ASSERT
argument_list|(
operator|!
name|m_image
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
return|return
operator|&
name|m_image
operator|->
name|image
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|flush
name|void
name|QWindowsBackingStore
operator|::
name|flush
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|,
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|offset
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|window
argument_list|)
expr_stmt|;
specifier|const
name|QRect
name|br
init|=
name|region
operator|.
name|boundingRect
argument_list|()
decl_stmt|;
if|if
condition|(
name|QWindowsContext
operator|::
name|verboseBackingStore
operator|>
literal|1
condition|)
name|qDebug
argument_list|()
operator|<<
name|__FUNCTION__
operator|<<
name|window
operator|<<
name|offset
operator|<<
name|br
expr_stmt|;
name|QWindowsWindow
modifier|*
name|rw
init|=
name|QWindowsWindow
operator|::
name|baseWindowOf
argument_list|(
name|window
argument_list|)
decl_stmt|;
ifndef|#
directive|ifndef
name|Q_OS_WINCE
specifier|const
name|bool
name|hasAlpha
init|=
name|rw
operator|->
name|format
argument_list|()
operator|.
name|hasAlpha
argument_list|()
decl_stmt|;
specifier|const
name|Qt
operator|::
name|WindowFlags
name|flags
init|=
name|window
operator|->
name|flags
argument_list|()
decl_stmt|;
if|if
condition|(
operator|(
name|flags
operator|&
name|Qt
operator|::
name|FramelessWindowHint
operator|)
operator|&&
name|QWindowsWindow
operator|::
name|setWindowLayered
argument_list|(
name|rw
operator|->
name|handle
argument_list|()
argument_list|,
name|flags
argument_list|,
name|hasAlpha
argument_list|,
name|rw
operator|->
name|opacity
argument_list|()
argument_list|)
operator|&&
name|hasAlpha
condition|)
block|{
comment|// Windows with alpha: Use blend function to update.
name|QRect
name|r
init|=
name|window
operator|->
name|frameGeometry
argument_list|()
decl_stmt|;
name|QPoint
name|frameOffset
argument_list|(
name|window
operator|->
name|frameMargins
argument_list|()
operator|.
name|left
argument_list|()
argument_list|,
name|window
operator|->
name|frameMargins
argument_list|()
operator|.
name|top
argument_list|()
argument_list|)
decl_stmt|;
name|QRect
name|dirtyRect
init|=
name|br
operator|.
name|translated
argument_list|(
name|offset
operator|+
name|frameOffset
argument_list|)
decl_stmt|;
name|SIZE
name|size
init|=
block|{
name|r
operator|.
name|width
argument_list|()
block|,
name|r
operator|.
name|height
argument_list|()
block|}
decl_stmt|;
name|POINT
name|ptDst
init|=
block|{
name|r
operator|.
name|x
argument_list|()
block|,
name|r
operator|.
name|y
argument_list|()
block|}
decl_stmt|;
name|POINT
name|ptSrc
init|=
block|{
literal|0
block|,
literal|0
block|}
decl_stmt|;
name|BLENDFUNCTION
name|blend
init|=
block|{
name|AC_SRC_OVER
block|,
literal|0
block|,
call|(
name|BYTE
call|)
argument_list|(
literal|255.0
operator|*
name|rw
operator|->
name|opacity
argument_list|()
argument_list|)
block|,
name|AC_SRC_ALPHA
block|}
decl_stmt|;
if|if
condition|(
name|QWindowsContext
operator|::
name|user32dll
operator|.
name|updateLayeredWindowIndirect
condition|)
block|{
name|RECT
name|dirty
init|=
block|{
name|dirtyRect
operator|.
name|x
argument_list|()
block|,
name|dirtyRect
operator|.
name|y
argument_list|()
block|,
name|dirtyRect
operator|.
name|x
argument_list|()
operator|+
name|dirtyRect
operator|.
name|width
argument_list|()
block|,
name|dirtyRect
operator|.
name|y
argument_list|()
operator|+
name|dirtyRect
operator|.
name|height
argument_list|()
block|}
decl_stmt|;
name|UPDATELAYEREDWINDOWINFO
name|info
init|=
block|{
sizeof|sizeof
argument_list|(
name|info
argument_list|)
block|,
name|NULL
block|,
operator|&
name|ptDst
block|,
operator|&
name|size
block|,
name|m_image
operator|->
name|hdc
argument_list|()
block|,
operator|&
name|ptSrc
block|,
literal|0
block|,
operator|&
name|blend
block|,
name|ULW_ALPHA
block|,
operator|&
name|dirty
block|}
decl_stmt|;
name|QWindowsContext
operator|::
name|user32dll
operator|.
name|updateLayeredWindowIndirect
argument_list|(
name|rw
operator|->
name|handle
argument_list|()
argument_list|,
operator|&
name|info
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QWindowsContext
operator|::
name|user32dll
operator|.
name|updateLayeredWindow
argument_list|(
name|rw
operator|->
name|handle
argument_list|()
argument_list|,
name|NULL
argument_list|,
operator|&
name|ptDst
argument_list|,
operator|&
name|size
argument_list|,
name|m_image
operator|->
name|hdc
argument_list|()
argument_list|,
operator|&
name|ptSrc
argument_list|,
literal|0
argument_list|,
operator|&
name|blend
argument_list|,
name|ULW_ALPHA
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
endif|#
directive|endif
specifier|const
name|HDC
name|dc
init|=
name|rw
operator|->
name|getDC
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|dc
condition|)
block|{
name|qErrnoWarning
argument_list|(
literal|"%s: GetDC failed"
argument_list|,
name|__FUNCTION__
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
operator|!
name|BitBlt
argument_list|(
name|dc
argument_list|,
name|br
operator|.
name|x
argument_list|()
argument_list|,
name|br
operator|.
name|y
argument_list|()
argument_list|,
name|br
operator|.
name|width
argument_list|()
argument_list|,
name|br
operator|.
name|height
argument_list|()
argument_list|,
name|m_image
operator|->
name|hdc
argument_list|()
argument_list|,
name|br
operator|.
name|x
argument_list|()
operator|+
name|offset
operator|.
name|x
argument_list|()
argument_list|,
name|br
operator|.
name|y
argument_list|()
operator|+
name|offset
operator|.
name|y
argument_list|()
argument_list|,
name|SRCCOPY
argument_list|)
condition|)
name|qErrnoWarning
argument_list|(
literal|"%s: BitBlt failed"
argument_list|,
name|__FUNCTION__
argument_list|)
expr_stmt|;
name|rw
operator|->
name|releaseDC
argument_list|()
expr_stmt|;
ifndef|#
directive|ifndef
name|Q_OS_WINCE
block|}
endif|#
directive|endif
comment|// Write image for debug purposes.
if|if
condition|(
name|QWindowsContext
operator|::
name|verboseBackingStore
operator|>
literal|2
condition|)
block|{
specifier|static
name|int
name|n
init|=
literal|0
decl_stmt|;
specifier|const
name|QString
name|fileName
init|=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"win%1_%2.png"
argument_list|)
operator|.
name|arg
argument_list|(
name|rw
operator|->
name|winId
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|n
operator|++
argument_list|)
decl_stmt|;
name|m_image
operator|->
name|image
argument_list|()
operator|.
name|save
argument_list|(
name|fileName
argument_list|)
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"Wrote "
operator|<<
name|m_image
operator|->
name|image
argument_list|()
operator|.
name|size
argument_list|()
operator|<<
name|fileName
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|resize
name|void
name|QWindowsBackingStore
operator|::
name|resize
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|)
block|{
if|if
condition|(
name|m_image
operator|.
name|isNull
argument_list|()
operator|||
name|m_image
operator|->
name|image
argument_list|()
operator|.
name|size
argument_list|()
operator|!=
name|size
condition|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_OUTPUT
if|if
condition|(
name|QWindowsContext
operator|::
name|verboseBackingStore
condition|)
block|{
name|QDebug
name|nsp
init|=
name|qDebug
argument_list|()
operator|.
name|nospace
argument_list|()
decl_stmt|;
name|nsp
operator|<<
name|__FUNCTION__
operator|<<
literal|' '
operator|<<
name|rasterWindow
argument_list|()
operator|->
name|window
argument_list|()
operator|<<
literal|' '
operator|<<
name|size
operator|<<
literal|' '
operator|<<
name|region
expr_stmt|;
if|if
condition|(
operator|!
name|m_image
operator|.
name|isNull
argument_list|()
condition|)
name|nsp
operator|<<
literal|" from: "
operator|<<
name|m_image
operator|->
name|image
argument_list|()
operator|.
name|size
argument_list|()
expr_stmt|;
block|}
endif|#
directive|endif
name|QImage
operator|::
name|Format
name|format
init|=
name|QWindowsNativeImage
operator|::
name|systemFormat
argument_list|()
decl_stmt|;
if|if
condition|(
name|format
operator|==
name|QImage
operator|::
name|Format_RGB32
operator|&&
name|rasterWindow
argument_list|()
operator|->
name|window
argument_list|()
operator|->
name|format
argument_list|()
operator|.
name|hasAlpha
argument_list|()
condition|)
name|format
operator|=
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
expr_stmt|;
name|m_image
operator|.
name|reset
argument_list|(
operator|new
name|QWindowsNativeImage
argument_list|(
name|size
operator|.
name|width
argument_list|()
argument_list|,
name|size
operator|.
name|height
argument_list|()
argument_list|,
name|format
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function_decl
name|Q_GUI_EXPORT
name|void
name|qt_scrollRectInImage
parameter_list|(
name|QImage
modifier|&
name|img
parameter_list|,
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|offset
parameter_list|)
function_decl|;
end_function_decl
begin_function
DECL|function|scroll
name|bool
name|QWindowsBackingStore
operator|::
name|scroll
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|area
parameter_list|,
name|int
name|dx
parameter_list|,
name|int
name|dy
parameter_list|)
block|{
if|if
condition|(
name|m_image
operator|.
name|isNull
argument_list|()
operator|||
name|m_image
operator|->
name|image
argument_list|()
operator|.
name|isNull
argument_list|()
condition|)
return|return
literal|false
return|;
specifier|const
name|QVector
argument_list|<
name|QRect
argument_list|>
name|rects
init|=
name|area
operator|.
name|rects
argument_list|()
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
name|rects
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|qt_scrollRectInImage
argument_list|(
name|m_image
operator|->
name|image
argument_list|()
argument_list|,
name|rects
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|,
name|QPoint
argument_list|(
name|dx
argument_list|,
name|dy
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|beginPaint
name|void
name|QWindowsBackingStore
operator|::
name|beginPaint
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|)
block|{
if|if
condition|(
name|QWindowsContext
operator|::
name|verboseBackingStore
operator|>
literal|1
condition|)
name|qDebug
argument_list|()
operator|<<
name|__FUNCTION__
expr_stmt|;
if|if
condition|(
name|m_image
operator|->
name|image
argument_list|()
operator|.
name|hasAlphaChannel
argument_list|()
condition|)
block|{
name|QPainter
name|p
argument_list|(
operator|&
name|m_image
operator|->
name|image
argument_list|()
argument_list|)
decl_stmt|;
name|p
operator|.
name|setCompositionMode
argument_list|(
name|QPainter
operator|::
name|CompositionMode_Source
argument_list|)
expr_stmt|;
specifier|const
name|QColor
name|blank
init|=
name|Qt
operator|::
name|transparent
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QRect
modifier|&
name|r
decl|,
name|region
operator|.
name|rects
argument_list|()
control|)
name|p
operator|.
name|fillRect
argument_list|(
name|r
argument_list|,
name|blank
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|rasterWindow
name|QWindowsWindow
modifier|*
name|QWindowsBackingStore
operator|::
name|rasterWindow
parameter_list|()
specifier|const
block|{
if|if
condition|(
specifier|const
name|QWindow
modifier|*
name|w
init|=
name|window
argument_list|()
condition|)
if|if
condition|(
name|QPlatformWindow
modifier|*
name|pw
init|=
name|w
operator|->
name|handle
argument_list|()
condition|)
return|return
cast|static_cast
argument_list|<
name|QWindowsWindow
operator|*
argument_list|>
argument_list|(
name|pw
argument_list|)
return|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|getDC
name|HDC
name|QWindowsBackingStore
operator|::
name|getDC
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|m_image
operator|.
name|isNull
argument_list|()
condition|)
return|return
name|m_image
operator|->
name|hdc
argument_list|()
return|;
return|return
literal|0
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
