begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINRTTHEME_H
end_ifndef
begin_define
DECL|macro|QWINRTTHEME_H
define|#
directive|define
name|QWINRTTHEME_H
end_define
begin_include
include|#
directive|include
file|<qpa/qplatformtheme.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformintegration.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QWinRTThemePrivate
name|class
name|QWinRTThemePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QWinRTTheme
range|:
name|public
name|QPlatformTheme
block|{
name|public
operator|:
name|QWinRTTheme
argument_list|()
block|;
name|bool
name|usePlatformNativeDialog
argument_list|(
argument|DialogType type
argument_list|)
specifier|const
block|;
name|QPlatformDialogHelper
operator|*
name|createPlatformDialogHelper
argument_list|(
argument|DialogType type
argument_list|)
specifier|const
block|;
specifier|const
name|QPalette
operator|*
name|palette
argument_list|(
argument|Palette type = SystemPalette
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
specifier|static
name|QVariant
name|styleHint
argument_list|(
argument|QPlatformIntegration::StyleHint hint
argument_list|)
block|;
name|private
operator|:
name|QScopedPointer
operator|<
name|QWinRTThemePrivate
operator|>
name|d_ptr
block|;
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QWinRTTheme
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWINRTTHEME_H
end_comment
end_unit