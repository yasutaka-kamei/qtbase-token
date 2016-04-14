begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qimagepixmapcleanuphooks_p.h"
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformpixmap.h>
end_include
begin_include
include|#
directive|include
file|"private/qimage_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|Q_GLOBAL_STATIC
argument_list|(
name|QImagePixmapCleanupHooks
argument_list|,
name|qt_image_and_pixmap_cleanup_hooks
argument_list|)
DECL|function|instance
name|QImagePixmapCleanupHooks
modifier|*
name|QImagePixmapCleanupHooks
operator|::
name|instance
argument_list|()
argument_list|{     return
name|qt_image_and_pixmap_cleanup_hooks
argument_list|()
argument_list|; }
DECL|function|addPlatformPixmapModificationHook
name|void
name|QImagePixmapCleanupHooks
operator|::
name|addPlatformPixmapModificationHook
argument_list|(
name|_qt_pixmap_cleanup_hook_pmd
name|hook
argument_list|)
argument_list|{
name|pixmapModificationHooks
operator|.
name|append
argument_list|(
name|hook
argument_list|)
argument_list|; }
DECL|function|addPlatformPixmapDestructionHook
name|void
name|QImagePixmapCleanupHooks
operator|::
name|addPlatformPixmapDestructionHook
argument_list|(
name|_qt_pixmap_cleanup_hook_pmd
name|hook
argument_list|)
argument_list|{
name|pixmapDestructionHooks
operator|.
name|append
argument_list|(
name|hook
argument_list|)
argument_list|; }
DECL|function|addImageHook
name|void
name|QImagePixmapCleanupHooks
operator|::
name|addImageHook
argument_list|(
name|_qt_image_cleanup_hook_64
name|hook
argument_list|)
argument_list|{
name|imageHooks
operator|.
name|append
argument_list|(
name|hook
argument_list|)
argument_list|; }
DECL|function|removePlatformPixmapModificationHook
name|void
name|QImagePixmapCleanupHooks
operator|::
name|removePlatformPixmapModificationHook
argument_list|(
name|_qt_pixmap_cleanup_hook_pmd
name|hook
argument_list|)
argument_list|{
name|pixmapModificationHooks
operator|.
name|removeAll
argument_list|(
name|hook
argument_list|)
argument_list|; }
DECL|function|removePlatformPixmapDestructionHook
name|void
name|QImagePixmapCleanupHooks
operator|::
name|removePlatformPixmapDestructionHook
argument_list|(
name|_qt_pixmap_cleanup_hook_pmd
name|hook
argument_list|)
argument_list|{
name|pixmapDestructionHooks
operator|.
name|removeAll
argument_list|(
name|hook
argument_list|)
argument_list|; }
DECL|function|removeImageHook
name|void
name|QImagePixmapCleanupHooks
operator|::
name|removeImageHook
argument_list|(
name|_qt_image_cleanup_hook_64
name|hook
argument_list|)
argument_list|{
name|imageHooks
operator|.
name|removeAll
argument_list|(
name|hook
argument_list|)
argument_list|; }
DECL|function|executePlatformPixmapModificationHooks
name|void
name|QImagePixmapCleanupHooks
operator|::
name|executePlatformPixmapModificationHooks
argument_list|(
name|QPlatformPixmap
operator|*
name|pmd
argument_list|)
argument_list|{
specifier|const
name|QImagePixmapCleanupHooks
operator|*
name|h
operator|=
name|qt_image_and_pixmap_cleanup_hooks
argument_list|()
argument_list|;
comment|// the global destructor for the pixmap and image hooks might have
comment|// been called already if the app is "leaking" global
comment|// pixmaps/images
argument_list|if
operator|(
operator|!
name|h
operator|)
return|return;
end_decl_stmt
begin_for
for|for
control|(
name|auto
name|hook
range|:
name|h
operator|->
name|pixmapModificationHooks
control|)
name|hook
argument_list|(
name|pmd
argument_list|)
expr_stmt|;
end_for
begin_macro
unit|}  void
DECL|function|executePlatformPixmapDestructionHooks
name|QImagePixmapCleanupHooks
end_macro
begin_expr_stmt
DECL|function|executePlatformPixmapDestructionHooks
operator|::
name|executePlatformPixmapDestructionHooks
operator|(
name|QPlatformPixmap
operator|*
name|pmd
operator|)
block|{
specifier|const
name|QImagePixmapCleanupHooks
operator|*
name|h
operator|=
name|qt_image_and_pixmap_cleanup_hooks
argument_list|()
block|;
comment|// the global destructor for the pixmap and image hooks might have
comment|// been called already if the app is "leaking" global
comment|// pixmaps/images
if|if
condition|(
operator|!
name|h
condition|)
return|return;
end_expr_stmt
begin_for
for|for
control|(
name|auto
name|hook
range|:
name|h
operator|->
name|pixmapDestructionHooks
control|)
name|hook
argument_list|(
name|pmd
argument_list|)
expr_stmt|;
end_for
begin_macro
unit|}  void
DECL|function|executeImageHooks
name|QImagePixmapCleanupHooks
end_macro
begin_expr_stmt
DECL|function|executeImageHooks
operator|::
name|executeImageHooks
operator|(
name|qint64
name|key
operator|)
block|{
specifier|const
name|QImagePixmapCleanupHooks
operator|*
name|h
operator|=
name|qt_image_and_pixmap_cleanup_hooks
argument_list|()
block|;
comment|// the global destructor for the pixmap and image hooks might have
comment|// been called already if the app is "leaking" global
comment|// pixmaps/images
if|if
condition|(
operator|!
name|h
condition|)
return|return;
end_expr_stmt
begin_for
for|for
control|(
name|auto
name|hook
range|:
name|h
operator|->
name|imageHooks
control|)
name|hook
argument_list|(
name|key
argument_list|)
expr_stmt|;
end_for
begin_macro
unit|}   void
DECL|function|enableCleanupHooks
name|QImagePixmapCleanupHooks
end_macro
begin_expr_stmt
DECL|function|enableCleanupHooks
operator|::
name|enableCleanupHooks
operator|(
name|QPlatformPixmap
operator|*
name|handle
operator|)
block|{
name|handle
operator|->
name|is_cached
operator|=
literal|true
block|; }
DECL|function|enableCleanupHooks
name|void
name|QImagePixmapCleanupHooks
operator|::
name|enableCleanupHooks
operator|(
specifier|const
name|QPixmap
operator|&
name|pixmap
operator|)
block|{
name|enableCleanupHooks
argument_list|(
cast|const_cast
argument_list|<
name|QPixmap
operator|&
argument_list|>
argument_list|(
name|pixmap
argument_list|)
operator|.
name|data_ptr
argument_list|()
operator|.
name|data
argument_list|()
argument_list|)
block|; }
DECL|function|enableCleanupHooks
name|void
name|QImagePixmapCleanupHooks
operator|::
name|enableCleanupHooks
operator|(
specifier|const
name|QImage
operator|&
name|image
operator|)
block|{
cast|const_cast
argument_list|<
name|QImage
operator|&
argument_list|>
argument_list|(
name|image
argument_list|)
operator|.
name|data_ptr
argument_list|()
operator|->
name|is_cached
operator|=
literal|true
block|; }
DECL|function|isImageCached
name|bool
name|QImagePixmapCleanupHooks
operator|::
name|isImageCached
operator|(
specifier|const
name|QImage
operator|&
name|image
operator|)
block|{
return|return
cast|const_cast
argument_list|<
name|QImage
operator|&
argument_list|>
argument_list|(
name|image
argument_list|)
operator|.
name|data_ptr
argument_list|()
operator|->
name|is_cached
return|;
block|}
end_expr_stmt
begin_function
DECL|function|isPixmapCached
name|bool
name|QImagePixmapCleanupHooks
operator|::
name|isPixmapCached
parameter_list|(
specifier|const
name|QPixmap
modifier|&
name|pixmap
parameter_list|)
block|{
return|return
cast|const_cast
argument_list|<
name|QPixmap
operator|&
argument_list|>
argument_list|(
name|pixmap
argument_list|)
operator|.
name|data_ptr
argument_list|()
operator|.
name|data
argument_list|()
operator|->
name|is_cached
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
