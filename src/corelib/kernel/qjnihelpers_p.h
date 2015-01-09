begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QJNIHELPERS_H
end_ifndef
begin_define
DECL|macro|QJNIHELPERS_H
define|#
directive|define
name|QJNIHELPERS_H
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
file|<jni.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QRunnable
name|class
name|QRunnable
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|namespace
name|QtAndroidPrivate
block|{
name|class
name|Q_CORE_EXPORT
name|ActivityResultListener
block|{
name|public
label|:
name|virtual
operator|~
name|ActivityResultListener
argument_list|()
block|{}
name|virtual
name|bool
name|handleActivityResult
argument_list|(
argument|jint requestCode
argument_list|,
argument|jint resultCode
argument_list|,
argument|jobject data
argument_list|)
operator|=
literal|0
expr_stmt|;
block|}
empty_stmt|;
name|class
name|Q_CORE_EXPORT
name|NewIntentListener
block|{
name|public
label|:
name|virtual
operator|~
name|NewIntentListener
argument_list|()
block|{}
name|virtual
name|bool
name|handleNewIntent
argument_list|(
argument|JNIEnv *env
argument_list|,
argument|jobject intent
argument_list|)
operator|=
literal|0
expr_stmt|;
block|}
empty_stmt|;
name|Q_CORE_EXPORT
name|jobject
name|activity
parameter_list|()
function_decl|;
name|Q_CORE_EXPORT
name|JavaVM
modifier|*
name|javaVM
parameter_list|()
function_decl|;
name|Q_CORE_EXPORT
name|jint
name|initJNI
parameter_list|(
name|JavaVM
modifier|*
name|vm
parameter_list|,
name|JNIEnv
modifier|*
name|env
parameter_list|)
function_decl|;
name|jobject
name|classLoader
parameter_list|()
function_decl|;
name|Q_CORE_EXPORT
name|jint
name|androidSdkVersion
parameter_list|()
function_decl|;
name|Q_CORE_EXPORT
name|void
name|runOnUiThread
parameter_list|(
name|QRunnable
modifier|*
name|runnable
parameter_list|,
name|JNIEnv
modifier|*
name|env
parameter_list|)
function_decl|;
name|Q_CORE_EXPORT
name|void
name|handleActivityResult
parameter_list|(
name|jint
name|requestCode
parameter_list|,
name|jint
name|resultCode
parameter_list|,
name|jobject
name|data
parameter_list|)
function_decl|;
name|Q_CORE_EXPORT
name|void
name|registerActivityResultListener
parameter_list|(
name|ActivityResultListener
modifier|*
name|listener
parameter_list|)
function_decl|;
name|Q_CORE_EXPORT
name|void
name|unregisterActivityResultListener
parameter_list|(
name|ActivityResultListener
modifier|*
name|listener
parameter_list|)
function_decl|;
name|Q_CORE_EXPORT
name|void
name|handleNewIntent
parameter_list|(
name|JNIEnv
modifier|*
name|env
parameter_list|,
name|jobject
name|intent
parameter_list|)
function_decl|;
name|Q_CORE_EXPORT
name|void
name|registerNewIntentListener
parameter_list|(
name|NewIntentListener
modifier|*
name|listener
parameter_list|)
function_decl|;
name|Q_CORE_EXPORT
name|void
name|unregisterNewIntentListener
parameter_list|(
name|NewIntentListener
modifier|*
name|listener
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
comment|// QJNIHELPERS_H
end_comment
end_unit
