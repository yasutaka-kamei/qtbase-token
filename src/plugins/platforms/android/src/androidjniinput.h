begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 BogDan Vatra<bogdan@kde.org> ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|ANDROIDJNIINPUT_H
end_ifndef
begin_define
DECL|macro|ANDROIDJNIINPUT_H
define|#
directive|define
name|ANDROIDJNIINPUT_H
end_define
begin_include
include|#
directive|include
file|<jni.h>
end_include
begin_decl_stmt
name|namespace
name|QtAndroidInput
block|{
comment|// Software keyboard support
name|void
name|showSoftwareKeyboard
parameter_list|(
name|int
name|top
parameter_list|,
name|int
name|left
parameter_list|,
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|,
name|int
name|inputHints
parameter_list|)
function_decl|;
name|void
name|resetSoftwareKeyboard
parameter_list|()
function_decl|;
name|void
name|hideSoftwareKeyboard
parameter_list|()
function_decl|;
name|bool
name|isSoftwareKeyboardVisible
parameter_list|()
function_decl|;
name|void
name|updateSelection
parameter_list|(
name|int
name|selStart
parameter_list|,
name|int
name|selEnd
parameter_list|,
name|int
name|candidatesStart
parameter_list|,
name|int
name|candidatesEnd
parameter_list|)
function_decl|;
comment|// Software keyboard support
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
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// ANDROIDJNIINPUT_H
end_comment
end_unit
