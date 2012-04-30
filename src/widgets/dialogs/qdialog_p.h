begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDIALOG_P_H
end_ifndef
begin_define
DECL|macro|QDIALOG_P_H
define|#
directive|define
name|QDIALOG_P_H
end_define
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
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
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
begin_include
include|#
directive|include
file|"private/qwidget_p.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qeventloop.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qpointer.h"
end_include
begin_include
include|#
directive|include
file|"QtWidgets/qdialog.h"
end_include
begin_include
include|#
directive|include
file|"QtWidgets/qpushbutton.h"
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformdialoghelper.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QSizeGrip
name|class
name|QSizeGrip
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QDialogPrivate
range|:
name|public
name|QWidgetPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QDialog
argument_list|)
name|public
operator|:
name|QDialogPrivate
argument_list|()
operator|:
name|mainDef
argument_list|(
literal|0
argument_list|)
block|,
name|orientation
argument_list|(
name|Qt
operator|::
name|Horizontal
argument_list|)
block|,
name|extension
argument_list|(
literal|0
argument_list|)
block|,
name|doShowExtension
argument_list|(
name|false
argument_list|)
block|,
ifndef|#
directive|ifndef
name|QT_NO_SIZEGRIP
name|resizer
argument_list|(
literal|0
argument_list|)
block|,
name|sizeGripEnabled
argument_list|(
name|false
argument_list|)
block|,
endif|#
directive|endif
name|rescode
argument_list|(
literal|0
argument_list|)
block|,
name|resetModalityTo
argument_list|(
operator|-
literal|1
argument_list|)
block|,
name|wasModalitySet
argument_list|(
name|true
argument_list|)
block|,
name|eventLoop
argument_list|(
literal|0
argument_list|)
block|,
name|nativeDialogInUse
argument_list|(
name|false
argument_list|)
block|,
name|m_platformHelper
argument_list|(
literal|0
argument_list|)
block|,
name|m_platformHelperCreated
argument_list|(
argument|false
argument_list|)
block|{}
operator|~
name|QDialogPrivate
argument_list|()
block|{
name|delete
name|m_platformHelper
block|; }
name|QWindow
operator|*
name|parentWindow
argument_list|()
specifier|const
block|;
name|bool
name|setNativeDialogVisible
argument_list|(
argument|bool visible
argument_list|)
block|;
name|QVariant
name|styleHint
argument_list|(
argument|QPlatformDialogHelper::StyleHint hint
argument_list|)
specifier|const
block|;
name|void
name|deleteNativeDialog
argument_list|()
block|;
name|QPointer
operator|<
name|QPushButton
operator|>
name|mainDef
block|;
name|Qt
operator|::
name|Orientation
name|orientation
block|;
name|QWidget
operator|*
name|extension
block|;
name|bool
name|doShowExtension
block|;
name|QSize
name|size
block|,
name|min
block|,
name|max
block|;
ifndef|#
directive|ifndef
name|QT_NO_SIZEGRIP
name|QSizeGrip
operator|*
name|resizer
block|;
name|bool
name|sizeGripEnabled
block|;
endif|#
directive|endif
name|QPoint
name|lastRMBPress
block|;
name|void
name|setDefault
argument_list|(
name|QPushButton
operator|*
argument_list|)
block|;
name|void
name|setMainDefault
argument_list|(
name|QPushButton
operator|*
argument_list|)
block|;
name|void
name|hideDefault
argument_list|()
block|;
name|void
name|resetModalitySetByOpen
argument_list|()
block|;
ifdef|#
directive|ifdef
name|Q_OS_WINCE_WM
name|void
name|_q_doneAction
argument_list|()
block|;
endif|#
directive|endif
name|int
name|rescode
block|;
name|int
name|resetModalityTo
block|;
name|bool
name|wasModalitySet
block|;
name|QPointer
operator|<
name|QEventLoop
operator|>
name|eventLoop
block|;
name|bool
name|nativeDialogInUse
block|;
comment|// Assigned in setVisible_sys() in derived classes.
name|QPlatformDialogHelper
operator|*
name|platformHelper
argument_list|()
specifier|const
block|;
name|private
operator|:
name|virtual
name|void
name|initHelper
argument_list|(
argument|QPlatformDialogHelper *
argument_list|)
block|{}
name|virtual
name|void
name|helperPrepareShow
argument_list|(
argument|QPlatformDialogHelper *
argument_list|)
block|{}
name|virtual
name|void
name|helperDone
argument_list|(
argument|QDialog::DialogCode
argument_list|,
argument|QPlatformDialogHelper *
argument_list|)
block|{}
name|mutable
name|QPlatformDialogHelper
operator|*
name|m_platformHelper
block|;
name|mutable
name|bool
name|m_platformHelperCreated
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
comment|// QDIALOG_P_H
end_comment
end_unit
