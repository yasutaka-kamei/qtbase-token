begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwindowsdirect2dbackingstore.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsdirect2dplatformpixmap.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsdirect2dintegration.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsdirect2dcontext.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsdirect2dpaintdevice.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsdirect2dbitmap.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsdirect2ddevicecontext.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsdirect2dwindow.h"
end_include
begin_include
include|#
directive|include
file|"qwindowscontext.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QPainter>
end_include
begin_include
include|#
directive|include
file|<QtGui/QWindow>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*!     \class QWindowsDirect2DBackingStore     \brief Backing store for windows.     \internal     \ingroup qt-lighthouse-win */
DECL|function|platformPixmap
specifier|static
specifier|inline
name|QWindowsDirect2DPlatformPixmap
modifier|*
name|platformPixmap
parameter_list|(
name|QPixmap
modifier|*
name|p
parameter_list|)
block|{
return|return
cast|static_cast
argument_list|<
name|QWindowsDirect2DPlatformPixmap
operator|*
argument_list|>
argument_list|(
name|p
operator|->
name|handle
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|bitmap
specifier|static
specifier|inline
name|QWindowsDirect2DBitmap
modifier|*
name|bitmap
parameter_list|(
name|QPixmap
modifier|*
name|p
parameter_list|)
block|{
return|return
name|platformPixmap
argument_list|(
name|p
argument_list|)
operator|->
name|bitmap
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|nativeWindow
specifier|static
specifier|inline
name|QWindowsDirect2DWindow
modifier|*
name|nativeWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
block|{
return|return
cast|static_cast
argument_list|<
name|QWindowsDirect2DWindow
operator|*
argument_list|>
argument_list|(
name|window
operator|->
name|handle
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_constructor
DECL|function|QWindowsDirect2DBackingStore
name|QWindowsDirect2DBackingStore
operator|::
name|QWindowsDirect2DBackingStore
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
block|{ }
end_constructor
begin_destructor
DECL|function|~QWindowsDirect2DBackingStore
name|QWindowsDirect2DBackingStore
operator|::
name|~
name|QWindowsDirect2DBackingStore
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|beginPaint
name|void
name|QWindowsDirect2DBackingStore
operator|::
name|beginPaint
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|)
block|{
name|QPixmap
modifier|*
name|pixmap
init|=
name|nativeWindow
argument_list|(
name|window
argument_list|()
argument_list|)
operator|->
name|pixmap
argument_list|()
decl_stmt|;
name|bitmap
argument_list|(
name|pixmap
argument_list|)
operator|->
name|deviceContext
argument_list|()
operator|->
name|begin
argument_list|()
expr_stmt|;
name|QPainter
name|painter
argument_list|(
name|pixmap
argument_list|)
decl_stmt|;
name|QColor
name|clear
argument_list|(
name|Qt
operator|::
name|transparent
argument_list|)
decl_stmt|;
name|painter
operator|.
name|setCompositionMode
argument_list|(
name|QPainter
operator|::
name|CompositionMode_Source
argument_list|)
expr_stmt|;
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
name|painter
operator|.
name|fillRect
argument_list|(
name|r
argument_list|,
name|clear
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|endPaint
name|void
name|QWindowsDirect2DBackingStore
operator|::
name|endPaint
parameter_list|()
block|{
name|bitmap
argument_list|(
name|nativeWindow
argument_list|(
name|window
argument_list|()
argument_list|)
operator|->
name|pixmap
argument_list|()
argument_list|)
operator|->
name|deviceContext
argument_list|()
operator|->
name|end
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|paintDevice
name|QPaintDevice
modifier|*
name|QWindowsDirect2DBackingStore
operator|::
name|paintDevice
parameter_list|()
block|{
return|return
name|nativeWindow
argument_list|(
name|window
argument_list|()
argument_list|)
operator|->
name|pixmap
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|flush
name|void
name|QWindowsDirect2DBackingStore
operator|::
name|flush
parameter_list|(
name|QWindow
modifier|*
name|targetWindow
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
if|if
condition|(
name|targetWindow
operator|!=
name|window
argument_list|()
condition|)
block|{
name|QSharedPointer
argument_list|<
name|QWindowsDirect2DBitmap
argument_list|>
name|copy
argument_list|(
name|nativeWindow
argument_list|(
name|window
argument_list|()
argument_list|)
operator|->
name|copyBackBuffer
argument_list|()
argument_list|)
decl_stmt|;
name|nativeWindow
argument_list|(
name|targetWindow
argument_list|)
operator|->
name|flush
argument_list|(
name|copy
operator|.
name|data
argument_list|()
argument_list|,
name|region
argument_list|,
name|offset
argument_list|)
expr_stmt|;
block|}
name|nativeWindow
argument_list|(
name|targetWindow
argument_list|)
operator|->
name|present
argument_list|(
name|region
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|resize
name|void
name|QWindowsDirect2DBackingStore
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
name|QPixmap
name|old
init|=
name|nativeWindow
argument_list|(
name|window
argument_list|()
argument_list|)
operator|->
name|pixmap
argument_list|()
operator|->
name|copy
argument_list|()
decl_stmt|;
name|nativeWindow
argument_list|(
name|window
argument_list|()
argument_list|)
operator|->
name|resizeSwapChain
argument_list|(
name|size
argument_list|)
expr_stmt|;
name|QPixmap
modifier|*
name|newPixmap
init|=
name|nativeWindow
argument_list|(
name|window
argument_list|()
argument_list|)
operator|->
name|pixmap
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|old
operator|.
name|isNull
argument_list|()
condition|)
block|{
foreach|foreach
control|(
specifier|const
name|QRect
modifier|&
name|rect
decl|,
name|region
operator|.
name|rects
argument_list|()
control|)
block|{
name|platformPixmap
argument_list|(
name|newPixmap
argument_list|)
operator|->
name|copy
argument_list|(
name|old
operator|.
name|handle
argument_list|()
argument_list|,
name|rect
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
