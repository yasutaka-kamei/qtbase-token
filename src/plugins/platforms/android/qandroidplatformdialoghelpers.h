begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 BogDan Vatra<bogdan@kde.org> ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QANDROIDPLATFORMDIALOGHELPERS_H
end_ifndef
begin_define
DECL|macro|QANDROIDPLATFORMDIALOGHELPERS_H
define|#
directive|define
name|QANDROIDPLATFORMDIALOGHELPERS_H
end_define
begin_include
include|#
directive|include
file|<jni.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformdialoghelper.h>
end_include
begin_include
include|#
directive|include
file|<QEventLoop>
end_include
begin_include
include|#
directive|include
file|<private/qjni_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|namespace
name|QtAndroidDialogHelpers
block|{
name|class
name|QAndroidPlatformMessageDialogHelper
range|:
name|public
name|QPlatformMessageDialogHelper
block|{
name|Q_OBJECT
name|public
operator|:
name|QAndroidPlatformMessageDialogHelper
argument_list|()
block|;
name|void
name|exec
argument_list|()
block|;
name|bool
name|show
argument_list|(
argument|Qt::WindowFlags windowFlags
argument_list|,
argument|Qt::WindowModality windowModality
argument_list|,
argument|QWindow *parent
argument_list|)
block|;
name|void
name|hide
argument_list|()
block|;
name|public
name|slots
operator|:
name|void
name|dialogResult
argument_list|(
argument|int buttonID
argument_list|)
block|;
name|private
operator|:
name|void
name|addButtons
argument_list|(
argument|QSharedPointer<QMessageDialogOptions> opt
argument_list|,
argument|ButtonRole role
argument_list|)
block|;
name|private
operator|:
name|int
name|m_buttonId
block|;
name|QEventLoop
name|m_loop
block|;
name|QJNIObjectPrivate
name|m_javaMessageDialog
block|;
name|bool
name|m_shown
block|; }
decl_stmt|;
name|bool
name|registerNatives
parameter_list|(
name|JNIEnv
modifier|*
name|env
parameter_list|)
function_decl|;
block|}
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QANDROIDPLATFORMDIALOGHELPERS_H
end_comment
end_unit
