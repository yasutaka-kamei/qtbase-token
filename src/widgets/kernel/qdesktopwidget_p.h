begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of other Qt classes.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDESKTOPWIDGET_P_H
end_ifndef
begin_define
DECL|macro|QDESKTOPWIDGET_P_H
define|#
directive|define
name|QDESKTOPWIDGET_P_H
end_define
begin_include
include|#
directive|include
file|"QDesktopWidget"
end_include
begin_include
include|#
directive|include
file|"private/qwidget_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qalgorithms.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QDesktopScreenWidget
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|QDesktopScreenWidget
argument_list|(
name|QScreen
operator|*
name|screen
argument_list|,
specifier|const
name|QRect
operator|&
name|geometry
argument_list|)
block|;
name|int
name|screenNumber
argument_list|()
specifier|const
block|;
name|void
name|setScreenGeometry
argument_list|(
specifier|const
name|QRect
operator|&
name|geometry
argument_list|)
block|;
name|QScreen
operator|*
name|screen
argument_list|()
specifier|const
block|{
return|return
name|m_screen
operator|.
name|data
argument_list|()
return|;
block|}
name|QRect
name|screenGeometry
argument_list|()
specifier|const
block|{
return|return
name|m_geometry
return|;
block|}
name|private
operator|:
comment|// The widget updates its screen and geometry automatically. We need to save them separately
comment|// to detect changes, and trigger the appropriate signals.
specifier|const
name|QPointer
operator|<
name|QScreen
operator|>
name|m_screen
block|;
name|QRect
name|m_geometry
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QDesktopWidgetPrivate
range|:
name|public
name|QWidgetPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QDesktopWidget
argument_list|)
name|public
operator|:
operator|~
name|QDesktopWidgetPrivate
argument_list|()
block|{
name|qDeleteAll
argument_list|(
name|screens
argument_list|)
block|; }
name|void
name|_q_updateScreens
argument_list|()
block|;
name|void
name|_q_availableGeometryChanged
argument_list|()
block|;
name|QDesktopScreenWidget
operator|*
name|widgetForScreen
argument_list|(
argument|QScreen *qScreen
argument_list|)
specifier|const
block|;
name|QList
operator|<
name|QDesktopScreenWidget
operator|*
operator|>
name|screens
block|; }
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
comment|// QDESKTOPWIDGET_QPA_P_H
end_comment
end_unit
