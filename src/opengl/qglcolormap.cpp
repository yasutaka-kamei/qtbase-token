begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtOpenGL module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/*!     \class QGLColormap     \brief The QGLColormap class is used for installing custom colormaps into     a QGLWidget.      \inmodule OpenGL     \ingroup painting-3D     \ingroup shared      QGLColormap provides a platform independent way of specifying and     installing indexed colormaps for a QGLWidget. QGLColormap is     especially useful when using the OpenGL color-index mode.      Under X11 you must use an X server that supports either a \c     PseudoColor or \c DirectColor visual class. If your X server     currently only provides a \c GrayScale, \c TrueColor, \c     StaticColor or \c StaticGray visual, you will not be able to     allocate colorcells for writing. If this is the case, try setting     your X server to 8 bit mode. It should then provide you with at     least a \c PseudoColor visual. Note that you may experience     colormap flashing if your X server is running in 8 bit mode.      The size() of the colormap is always set to 256     colors. Note that under Windows you can also install colormaps     in child widgets.      This class uses \l{implicit sharing} as a memory and speed     optimization.      Example of use:     \snippet code/src_opengl_qglcolormap.cpp 0      \sa QGLWidget::setColormap(), QGLWidget::colormap() */
end_comment
begin_comment
comment|/*!     \fn Qt::HANDLE QGLColormap::handle()      \internal      Returns the handle for this color map. */
end_comment
begin_comment
comment|/*!     \fn void QGLColormap::setHandle(Qt::HANDLE handle)      \internal      Sets the handle for this color map to \a handle. */
end_comment
begin_include
include|#
directive|include
file|"qglcolormap.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|member|shared_null
name|QGLColormap
operator|::
name|QGLColormapData
name|QGLColormap
operator|::
name|shared_null
init|=
block|{
name|Q_BASIC_ATOMIC_INITIALIZER
argument_list|(
literal|1
argument_list|)
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt
begin_comment
comment|/*!     Construct a QGLColormap. */
end_comment
begin_constructor
DECL|function|QGLColormap
name|QGLColormap
operator|::
name|QGLColormap
parameter_list|()
member_init_list|:
name|d
argument_list|(
operator|&
name|shared_null
argument_list|)
block|{
name|d
operator|->
name|ref
operator|.
name|ref
parameter_list|()
constructor_decl|;
block|}
end_constructor
begin_comment
comment|/*!     Construct a shallow copy of \a map. */
end_comment
begin_constructor
DECL|function|QGLColormap
name|QGLColormap
operator|::
name|QGLColormap
parameter_list|(
specifier|const
name|QGLColormap
modifier|&
name|map
parameter_list|)
member_init_list|:
name|d
argument_list|(
name|map
operator|.
name|d
argument_list|)
block|{
name|d
operator|->
name|ref
operator|.
name|ref
parameter_list|()
constructor_decl|;
block|}
end_constructor
begin_comment
comment|/*!     Dereferences the QGLColormap and deletes it if this was the last     reference to it. */
end_comment
begin_destructor
DECL|function|~QGLColormap
name|QGLColormap
operator|::
name|~
name|QGLColormap
parameter_list|()
block|{
if|if
condition|(
operator|!
name|d
operator|->
name|ref
operator|.
name|deref
argument_list|()
condition|)
name|cleanup
argument_list|(
name|d
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|cleanup
name|void
name|QGLColormap
operator|::
name|cleanup
parameter_list|(
name|QGLColormap
operator|::
name|QGLColormapData
modifier|*
name|x
parameter_list|)
block|{
operator|delete
name|x
operator|->
name|cells
expr_stmt|;
name|x
operator|->
name|cells
operator|=
literal|0
expr_stmt|;
operator|delete
name|x
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Assign a shallow copy of \a map to this QGLColormap. */
end_comment
begin_function
DECL|function|operator =
name|QGLColormap
modifier|&
name|QGLColormap
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|QGLColormap
modifier|&
name|map
parameter_list|)
block|{
name|map
operator|.
name|d
operator|->
name|ref
operator|.
name|ref
parameter_list|()
constructor_decl|;
if|if
condition|(
operator|!
name|d
operator|->
name|ref
operator|.
name|deref
argument_list|()
condition|)
name|cleanup
argument_list|(
name|d
argument_list|)
expr_stmt|;
name|d
operator|=
name|map
operator|.
name|d
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_function
begin_comment
comment|/*!     \fn void QGLColormap::detach()     \internal      Detaches this QGLColormap from the shared block. */
end_comment
begin_function
DECL|function|detach_helper
name|void
name|QGLColormap
operator|::
name|detach_helper
parameter_list|()
block|{
name|QGLColormapData
modifier|*
name|x
init|=
operator|new
name|QGLColormapData
decl_stmt|;
name|x
operator|->
name|ref
operator|.
name|store
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|x
operator|->
name|cmapHandle
operator|=
literal|0
expr_stmt|;
name|x
operator|->
name|cells
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|cells
condition|)
block|{
name|x
operator|->
name|cells
operator|=
operator|new
name|QVector
argument_list|<
name|QRgb
argument_list|>
argument_list|(
literal|256
argument_list|)
expr_stmt|;
operator|*
name|x
operator|->
name|cells
operator|=
operator|*
name|d
operator|->
name|cells
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|d
operator|->
name|ref
operator|.
name|deref
argument_list|()
condition|)
name|cleanup
argument_list|(
name|d
argument_list|)
expr_stmt|;
name|d
operator|=
name|x
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Set cell at index \a idx in the colormap to color \a color. */
end_comment
begin_function
DECL|function|setEntry
name|void
name|QGLColormap
operator|::
name|setEntry
parameter_list|(
name|int
name|idx
parameter_list|,
name|QRgb
name|color
parameter_list|)
block|{
name|detach
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|cells
condition|)
name|d
operator|->
name|cells
operator|=
operator|new
name|QVector
argument_list|<
name|QRgb
argument_list|>
argument_list|(
literal|256
argument_list|)
expr_stmt|;
name|d
operator|->
name|cells
operator|->
name|replace
argument_list|(
name|idx
argument_list|,
name|color
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Set an array of cells in this colormap. \a count is the number of     colors that should be set, \a colors is the array of colors, and     \a base is the starting index.  The first element in \a colors     is set at \a base in the colormap. */
end_comment
begin_function
DECL|function|setEntries
name|void
name|QGLColormap
operator|::
name|setEntries
parameter_list|(
name|int
name|count
parameter_list|,
specifier|const
name|QRgb
modifier|*
name|colors
parameter_list|,
name|int
name|base
parameter_list|)
block|{
name|detach
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|cells
condition|)
name|d
operator|->
name|cells
operator|=
operator|new
name|QVector
argument_list|<
name|QRgb
argument_list|>
argument_list|(
literal|256
argument_list|)
expr_stmt|;
name|Q_ASSERT_X
argument_list|(
name|colors
operator|&&
name|base
operator|>=
literal|0
operator|&&
operator|(
name|base
operator|+
name|count
operator|)
operator|<=
name|d
operator|->
name|cells
operator|->
name|size
argument_list|()
argument_list|,
literal|"QGLColormap::setEntries"
argument_list|,
literal|"preconditions not met"
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|count
condition|;
operator|++
name|i
control|)
name|setEntry
argument_list|(
name|base
operator|+
name|i
argument_list|,
name|colors
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the QRgb value in the colorcell with index \a idx. */
end_comment
begin_function
DECL|function|entryRgb
name|QRgb
name|QGLColormap
operator|::
name|entryRgb
parameter_list|(
name|int
name|idx
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|d
operator|==
operator|&
name|shared_null
operator|||
operator|!
name|d
operator|->
name|cells
condition|)
return|return
literal|0
return|;
else|else
return|return
name|d
operator|->
name|cells
operator|->
name|at
argument_list|(
name|idx
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \overload      Set the cell with index \a idx in the colormap to color \a color. */
end_comment
begin_function
DECL|function|setEntry
name|void
name|QGLColormap
operator|::
name|setEntry
parameter_list|(
name|int
name|idx
parameter_list|,
specifier|const
name|QColor
modifier|&
name|color
parameter_list|)
block|{
name|setEntry
argument_list|(
name|idx
argument_list|,
name|color
operator|.
name|rgb
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the QRgb value in the colorcell with index \a idx. */
end_comment
begin_function
DECL|function|entryColor
name|QColor
name|QGLColormap
operator|::
name|entryColor
parameter_list|(
name|int
name|idx
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|d
operator|==
operator|&
name|shared_null
operator|||
operator|!
name|d
operator|->
name|cells
condition|)
return|return
name|QColor
argument_list|()
return|;
else|else
return|return
name|QColor
argument_list|(
name|d
operator|->
name|cells
operator|->
name|at
argument_list|(
name|idx
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Returns true if the colormap is empty or it is not in use     by a QGLWidget; otherwise returns false.      A colormap with no color values set is considered to be empty.     For historical reasons, a colormap that has color values set     but which is not in use by a QGLWidget is also considered empty.      Compare size() with zero to determine if the colormap is empty     regardless of whether it is in use by a QGLWidget or not.      \sa size() */
end_comment
begin_function
DECL|function|isEmpty
name|bool
name|QGLColormap
operator|::
name|isEmpty
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|==
operator|&
name|shared_null
operator|||
name|d
operator|->
name|cells
operator|==
literal|0
operator|||
name|d
operator|->
name|cells
operator|->
name|size
argument_list|()
operator|==
literal|0
operator|||
name|d
operator|->
name|cmapHandle
operator|==
literal|0
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the number of colorcells in the colormap. */
end_comment
begin_function
DECL|function|size
name|int
name|QGLColormap
operator|::
name|size
parameter_list|()
specifier|const
block|{
return|return
name|d
operator|->
name|cells
condition|?
name|d
operator|->
name|cells
operator|->
name|size
argument_list|()
else|:
literal|0
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the index of the color \a color. If \a color is not in the     map, -1 is returned. */
end_comment
begin_function
DECL|function|find
name|int
name|QGLColormap
operator|::
name|find
parameter_list|(
name|QRgb
name|color
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|d
operator|->
name|cells
condition|)
return|return
name|d
operator|->
name|cells
operator|->
name|indexOf
argument_list|(
name|color
argument_list|)
return|;
return|return
operator|-
literal|1
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the index of the color that is the closest match to color     \a color. */
end_comment
begin_function
DECL|function|findNearest
name|int
name|QGLColormap
operator|::
name|findNearest
parameter_list|(
name|QRgb
name|color
parameter_list|)
specifier|const
block|{
name|int
name|idx
init|=
name|find
argument_list|(
name|color
argument_list|)
decl_stmt|;
if|if
condition|(
name|idx
operator|>=
literal|0
condition|)
return|return
name|idx
return|;
name|int
name|mapSize
init|=
name|size
argument_list|()
decl_stmt|;
name|int
name|mindist
init|=
literal|200000
decl_stmt|;
name|int
name|r
init|=
name|qRed
argument_list|(
name|color
argument_list|)
decl_stmt|;
name|int
name|g
init|=
name|qGreen
argument_list|(
name|color
argument_list|)
decl_stmt|;
name|int
name|b
init|=
name|qBlue
argument_list|(
name|color
argument_list|)
decl_stmt|;
name|int
name|rx
decl_stmt|,
name|gx
decl_stmt|,
name|bx
decl_stmt|,
name|dist
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
name|mapSize
condition|;
operator|++
name|i
control|)
block|{
name|QRgb
name|ci
init|=
name|d
operator|->
name|cells
operator|->
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|rx
operator|=
name|r
operator|-
name|qRed
argument_list|(
name|ci
argument_list|)
expr_stmt|;
name|gx
operator|=
name|g
operator|-
name|qGreen
argument_list|(
name|ci
argument_list|)
expr_stmt|;
name|bx
operator|=
name|b
operator|-
name|qBlue
argument_list|(
name|ci
argument_list|)
expr_stmt|;
name|dist
operator|=
name|rx
operator|*
name|rx
operator|+
name|gx
operator|*
name|gx
operator|+
name|bx
operator|*
name|bx
expr_stmt|;
comment|// calculate distance
if|if
condition|(
name|dist
operator|<
name|mindist
condition|)
block|{
comment|// minimal?
name|mindist
operator|=
name|dist
expr_stmt|;
name|idx
operator|=
name|i
expr_stmt|;
block|}
block|}
return|return
name|idx
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
