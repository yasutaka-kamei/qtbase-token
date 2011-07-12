begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qbackingstore.h>
end_include
begin_include
include|#
directive|include
file|<qwindow.h>
end_include
begin_include
include|#
directive|include
file|<qpixmap.h>
end_include
begin_include
include|#
directive|include
file|<qplatformbackingstore_qpa.h>
end_include
begin_include
include|#
directive|include
file|<private/qguiapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qwindow_p.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QBackingStorePrivate
class|class
name|QBackingStorePrivate
block|{
public|public:
DECL|function|QBackingStorePrivate
name|QBackingStorePrivate
parameter_list|(
name|QWindow
modifier|*
name|w
parameter_list|)
member_init_list|:
name|window
argument_list|(
name|w
argument_list|)
block|{     }
DECL|member|window
name|QWindow
modifier|*
name|window
decl_stmt|;
DECL|member|platformBackingStore
name|QPlatformBackingStore
modifier|*
name|platformBackingStore
decl_stmt|;
DECL|member|staticContents
name|QRegion
name|staticContents
decl_stmt|;
DECL|member|size
name|QSize
name|size
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|/*!     \class QBackingStore     \since 5.0      \brief The QBackingStore class provides the drawing area for top-level windows. */
end_comment
begin_comment
comment|/*!     \fn void QBackingStore::beginPaint(const QRegion&region)      This function is called before painting onto the surface begins,     with the \a region in which the painting will occur.      \sa endPaint(), paintDevice() */
end_comment
begin_comment
comment|/*!     \fn void QBackingStore::endPaint(const QRegion&region)      This function is called after painting onto the surface has ended,     with the \a region in which the painting was performed.      \sa beginPaint(), paintDevice() */
end_comment
begin_comment
comment|/*!     \fn void QBackingStore::flush(QWindow *window, const QRegion&region,                                   const QPoint&offset)      Flushes the given \a region from the specified \a window onto the     screen.      Note that the \a offset parameter is currently unused. */
end_comment
begin_function
DECL|function|flush
name|void
name|QBackingStore
operator|::
name|flush
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|,
name|QWindow
modifier|*
name|win
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|offset
parameter_list|)
block|{
if|if
condition|(
operator|!
name|win
condition|)
name|win
operator|=
name|window
argument_list|()
expr_stmt|;
name|d_ptr
operator|->
name|platformBackingStore
operator|->
name|flush
argument_list|(
name|win
argument_list|,
name|region
argument_list|,
name|offset
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \fn QPaintDevice* QBackingStore::paintDevice()      Implement this function to return the appropriate paint device. */
end_comment
begin_function
DECL|function|paintDevice
name|QPaintDevice
modifier|*
name|QBackingStore
operator|::
name|paintDevice
parameter_list|()
block|{
return|return
name|d_ptr
operator|->
name|platformBackingStore
operator|->
name|paintDevice
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Constructs an empty surface for the given top-level \a window. */
end_comment
begin_constructor
DECL|function|QBackingStore
name|QBackingStore
operator|::
name|QBackingStore
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
member_init_list|:
name|d_ptr
argument_list|(
operator|new
name|QBackingStorePrivate
argument_list|(
name|window
argument_list|)
argument_list|)
block|{
name|d_ptr
operator|->
name|platformBackingStore
operator|=
name|QGuiApplicationPrivate
operator|::
name|platformIntegration
argument_list|()
operator|->
name|createPlatformBackingStore
argument_list|(
name|window
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Destroys this surface. */
end_comment
begin_destructor
DECL|function|~QBackingStore
name|QBackingStore
operator|::
name|~
name|QBackingStore
parameter_list|()
block|{
operator|delete
name|d_ptr
operator|->
name|platformBackingStore
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!     Returns a pointer to the top-level window associated with this     surface. */
end_comment
begin_function
DECL|function|window
name|QWindow
modifier|*
name|QBackingStore
operator|::
name|window
parameter_list|()
specifier|const
block|{
return|return
name|d_ptr
operator|->
name|window
return|;
block|}
end_function
begin_function
DECL|function|beginPaint
name|void
name|QBackingStore
operator|::
name|beginPaint
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|)
block|{
name|d_ptr
operator|->
name|platformBackingStore
operator|->
name|beginPaint
argument_list|(
name|region
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|endPaint
name|void
name|QBackingStore
operator|::
name|endPaint
parameter_list|()
block|{
name|d_ptr
operator|->
name|platformBackingStore
operator|->
name|endPaint
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!       Sets the size of the windowsurface to be \a size.        \sa size() */
end_comment
begin_function
DECL|function|resize
name|void
name|QBackingStore
operator|::
name|resize
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|)
block|{
name|d_ptr
operator|->
name|size
operator|=
name|size
expr_stmt|;
name|d_ptr
operator|->
name|platformBackingStore
operator|->
name|resize
argument_list|(
name|size
argument_list|,
name|d_ptr
operator|->
name|staticContents
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the current size of the windowsurface. */
end_comment
begin_function
DECL|function|size
name|QSize
name|QBackingStore
operator|::
name|size
parameter_list|()
specifier|const
block|{
return|return
name|d_ptr
operator|->
name|size
return|;
block|}
end_function
begin_comment
comment|/*!     Scrolls the given \a area \a dx pixels to the right and \a dy     downward; both \a dx and \a dy may be negative.      Returns true if the area was scrolled successfully; false otherwise. */
end_comment
begin_function
DECL|function|scroll
name|bool
name|QBackingStore
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
name|Q_UNUSED
argument_list|(
name|area
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|dx
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|dy
argument_list|)
expr_stmt|;
return|return
name|d_ptr
operator|->
name|platformBackingStore
operator|->
name|scroll
argument_list|(
name|area
argument_list|,
name|dx
argument_list|,
name|dy
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|setStaticContents
name|void
name|QBackingStore
operator|::
name|setStaticContents
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|)
block|{
name|d_ptr
operator|->
name|staticContents
operator|=
name|region
expr_stmt|;
block|}
end_function
begin_function
DECL|function|staticContents
name|QRegion
name|QBackingStore
operator|::
name|staticContents
parameter_list|()
specifier|const
block|{
return|return
name|d_ptr
operator|->
name|staticContents
return|;
block|}
end_function
begin_function
DECL|function|hasStaticContents
name|bool
name|QBackingStore
operator|::
name|hasStaticContents
parameter_list|()
specifier|const
block|{
return|return
operator|!
name|d_ptr
operator|->
name|staticContents
operator|.
name|isEmpty
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|qt_scrollRectInImage
name|void
name|Q_GUI_EXPORT
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
block|{
comment|// make sure we don't detach
name|uchar
modifier|*
name|mem
init|=
cast|const_cast
argument_list|<
name|uchar
operator|*
argument_list|>
argument_list|(
cast|const_cast
argument_list|<
specifier|const
name|QImage
operator|&
argument_list|>
argument_list|(
name|img
argument_list|)
operator|.
name|bits
argument_list|()
argument_list|)
decl_stmt|;
name|int
name|lineskip
init|=
name|img
operator|.
name|bytesPerLine
argument_list|()
decl_stmt|;
name|int
name|depth
init|=
name|img
operator|.
name|depth
argument_list|()
operator|>>
literal|3
decl_stmt|;
specifier|const
name|QRect
name|imageRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|img
operator|.
name|width
argument_list|()
argument_list|,
name|img
operator|.
name|height
argument_list|()
argument_list|)
decl_stmt|;
specifier|const
name|QRect
name|r
init|=
name|rect
operator|&
name|imageRect
operator|&
name|imageRect
operator|.
name|translated
argument_list|(
operator|-
name|offset
argument_list|)
decl_stmt|;
specifier|const
name|QPoint
name|p
init|=
name|rect
operator|.
name|topLeft
argument_list|()
operator|+
name|offset
decl_stmt|;
if|if
condition|(
name|r
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
specifier|const
name|uchar
modifier|*
name|src
decl_stmt|;
name|uchar
modifier|*
name|dest
decl_stmt|;
if|if
condition|(
name|r
operator|.
name|top
argument_list|()
operator|<
name|p
operator|.
name|y
argument_list|()
condition|)
block|{
name|src
operator|=
name|mem
operator|+
name|r
operator|.
name|bottom
argument_list|()
operator|*
name|lineskip
operator|+
name|r
operator|.
name|left
argument_list|()
operator|*
name|depth
expr_stmt|;
name|dest
operator|=
name|mem
operator|+
operator|(
name|p
operator|.
name|y
argument_list|()
operator|+
name|r
operator|.
name|height
argument_list|()
operator|-
literal|1
operator|)
operator|*
name|lineskip
operator|+
name|p
operator|.
name|x
argument_list|()
operator|*
name|depth
expr_stmt|;
name|lineskip
operator|=
operator|-
name|lineskip
expr_stmt|;
block|}
else|else
block|{
name|src
operator|=
name|mem
operator|+
name|r
operator|.
name|top
argument_list|()
operator|*
name|lineskip
operator|+
name|r
operator|.
name|left
argument_list|()
operator|*
name|depth
expr_stmt|;
name|dest
operator|=
name|mem
operator|+
name|p
operator|.
name|y
argument_list|()
operator|*
name|lineskip
operator|+
name|p
operator|.
name|x
argument_list|()
operator|*
name|depth
expr_stmt|;
block|}
specifier|const
name|int
name|w
init|=
name|r
operator|.
name|width
argument_list|()
decl_stmt|;
name|int
name|h
init|=
name|r
operator|.
name|height
argument_list|()
decl_stmt|;
specifier|const
name|int
name|bytes
init|=
name|w
operator|*
name|depth
decl_stmt|;
comment|// overlapping segments?
if|if
condition|(
name|offset
operator|.
name|y
argument_list|()
operator|==
literal|0
operator|&&
name|qAbs
argument_list|(
name|offset
operator|.
name|x
argument_list|()
argument_list|)
operator|<
name|w
condition|)
block|{
do|do
block|{
operator|::
name|memmove
argument_list|(
name|dest
argument_list|,
name|src
argument_list|,
name|bytes
argument_list|)
expr_stmt|;
name|dest
operator|+=
name|lineskip
expr_stmt|;
name|src
operator|+=
name|lineskip
expr_stmt|;
block|}
do|while
condition|(
operator|--
name|h
condition|)
do|;
block|}
else|else
block|{
do|do
block|{
operator|::
name|memcpy
argument_list|(
name|dest
argument_list|,
name|src
argument_list|,
name|bytes
argument_list|)
expr_stmt|;
name|dest
operator|+=
name|lineskip
expr_stmt|;
name|src
operator|+=
name|lineskip
expr_stmt|;
block|}
do|while
condition|(
operator|--
name|h
condition|)
do|;
block|}
block|}
end_function
begin_function
DECL|function|handle
name|QPlatformBackingStore
modifier|*
name|QBackingStore
operator|::
name|handle
parameter_list|()
specifier|const
block|{
return|return
name|d_ptr
operator|->
name|platformBackingStore
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
