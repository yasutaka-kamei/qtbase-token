begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 BogDan Vatra<bogdan@kde.org> ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qandroidplatformdialoghelpers.h"
end_include
begin_include
include|#
directive|include
file|"androidjnimain.h"
end_include
begin_include
include|#
directive|include
file|<QTextDocument>
end_include
begin_include
include|#
directive|include
file|<private/qguiapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformtheme.h>
end_include
begin_namespace
DECL|namespace|QtAndroidDialogHelpers
namespace|namespace
name|QtAndroidDialogHelpers
block|{
DECL|member|g_messageDialogHelperClass
specifier|static
name|jclass
name|g_messageDialogHelperClass
init|=
literal|0
decl_stmt|;
DECL|function|QAndroidPlatformMessageDialogHelper
name|QAndroidPlatformMessageDialogHelper
operator|::
name|QAndroidPlatformMessageDialogHelper
parameter_list|()
member_init_list|:
name|m_buttonId
argument_list|(
operator|-
literal|1
argument_list|)
member_init_list|,
name|m_javaMessageDialog
argument_list|(
name|g_messageDialogHelperClass
argument_list|,
literal|"(Landroid/app/Activity;)V"
argument_list|,
name|QtAndroid
operator|::
name|activity
argument_list|()
argument_list|)
member_init_list|,
name|m_shown
argument_list|(
literal|false
argument_list|)
block|{ }
DECL|function|exec
name|void
name|QAndroidPlatformMessageDialogHelper
operator|::
name|exec
parameter_list|()
block|{
if|if
condition|(
operator|!
name|m_shown
condition|)
name|show
argument_list|(
name|Qt
operator|::
name|Dialog
argument_list|,
name|Qt
operator|::
name|ApplicationModal
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|m_loop
operator|.
name|exec
argument_list|()
expr_stmt|;
block|}
DECL|function|htmlText
specifier|static
name|QString
name|htmlText
parameter_list|(
name|QString
name|text
parameter_list|)
block|{
if|if
condition|(
name|Qt
operator|::
name|mightBeRichText
argument_list|(
name|text
argument_list|)
condition|)
return|return
name|text
return|;
name|text
operator|.
name|remove
argument_list|(
name|QLatin1Char
argument_list|(
literal|'\r'
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|text
operator|.
name|toHtmlEscaped
argument_list|()
operator|.
name|replace
argument_list|(
name|QLatin1Char
argument_list|(
literal|'\n'
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|"<br />"
argument_list|)
argument_list|)
return|;
block|}
DECL|function|show
name|bool
name|QAndroidPlatformMessageDialogHelper
operator|::
name|show
parameter_list|(
name|Qt
operator|::
name|WindowFlags
name|windowFlags
parameter_list|,
name|Qt
operator|::
name|WindowModality
name|windowModality
parameter_list|,
name|QWindow
modifier|*
name|parent
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
argument|windowFlags
argument_list|)
name|Q_UNUSED
argument_list|(
argument|windowModality
argument_list|)
name|Q_UNUSED
argument_list|(
argument|parent
argument_list|)
name|QSharedPointer
argument_list|<
name|QMessageDialogOptions
argument_list|>
name|opt
init|=
name|options
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|opt
operator|.
name|data
argument_list|()
condition|)
return|return
literal|false
return|;
name|m_javaMessageDialog
operator|.
name|callMethod
argument_list|<
name|void
argument_list|>
argument_list|(
literal|"setIcon"
argument_list|,
literal|"(I)V"
argument_list|,
name|opt
operator|->
name|icon
argument_list|()
argument_list|)
expr_stmt|;
name|QString
name|str
init|=
name|htmlText
argument_list|(
name|opt
operator|->
name|windowTitle
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|str
operator|.
name|isEmpty
argument_list|()
condition|)
name|m_javaMessageDialog
operator|.
name|callMethod
argument_list|<
name|void
argument_list|>
argument_list|(
literal|"setTile"
argument_list|,
literal|"(Ljava/lang/String;)V"
argument_list|,
name|QJNIObjectPrivate
operator|::
name|fromString
argument_list|(
name|str
argument_list|)
operator|.
name|object
argument_list|()
argument_list|)
expr_stmt|;
name|str
operator|=
name|htmlText
argument_list|(
name|opt
operator|->
name|text
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|str
operator|.
name|isEmpty
argument_list|()
condition|)
name|m_javaMessageDialog
operator|.
name|callMethod
argument_list|<
name|void
argument_list|>
argument_list|(
literal|"setText"
argument_list|,
literal|"(Ljava/lang/String;)V"
argument_list|,
name|QJNIObjectPrivate
operator|::
name|fromString
argument_list|(
name|str
argument_list|)
operator|.
name|object
argument_list|()
argument_list|)
expr_stmt|;
name|str
operator|=
name|htmlText
argument_list|(
name|opt
operator|->
name|informativeText
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|str
operator|.
name|isEmpty
argument_list|()
condition|)
name|m_javaMessageDialog
operator|.
name|callMethod
argument_list|<
name|void
argument_list|>
argument_list|(
literal|"setInformativeText"
argument_list|,
literal|"(Ljava/lang/String;)V"
argument_list|,
name|QJNIObjectPrivate
operator|::
name|fromString
argument_list|(
name|str
argument_list|)
operator|.
name|object
argument_list|()
argument_list|)
expr_stmt|;
name|str
operator|=
name|htmlText
argument_list|(
name|opt
operator|->
name|detailedText
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|str
operator|.
name|isEmpty
argument_list|()
condition|)
name|m_javaMessageDialog
operator|.
name|callMethod
argument_list|<
name|void
argument_list|>
argument_list|(
literal|"setDetailedText"
argument_list|,
literal|"(Ljava/lang/String;)V"
argument_list|,
name|QJNIObjectPrivate
operator|::
name|fromString
argument_list|(
name|str
argument_list|)
operator|.
name|object
argument_list|()
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
name|QPlatformDialogHelper
operator|::
name|FirstButton
init|;
name|i
operator|<
name|QPlatformDialogHelper
operator|::
name|LastButton
condition|;
name|i
operator|<<=
literal|1
control|)
block|{
if|if
condition|(
name|opt
operator|->
name|standardButtons
argument_list|()
operator|&
name|i
condition|)
block|{
specifier|const
name|QString
name|text
init|=
name|QGuiApplicationPrivate
operator|::
name|platformTheme
argument_list|()
operator|->
name|standardButtonText
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|m_javaMessageDialog
operator|.
name|callMethod
argument_list|<
name|void
argument_list|>
argument_list|(
literal|"addButton"
argument_list|,
literal|"(ILjava/lang/String;)V"
argument_list|,
name|i
argument_list|,
name|QJNIObjectPrivate
operator|::
name|fromString
argument_list|(
name|text
argument_list|)
operator|.
name|object
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
name|m_javaMessageDialog
operator|.
name|callMethod
argument_list|<
name|void
argument_list|>
argument_list|(
literal|"show"
argument_list|,
literal|"(J)V"
argument_list|,
name|jlong
argument_list|(
cast|static_cast
argument_list|<
name|QObject
operator|*
argument_list|>
argument_list|(
name|this
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|m_shown
operator|=
literal|true
expr_stmt|;
return|return
literal|true
return|;
block|}
DECL|function|hide
name|void
name|QAndroidPlatformMessageDialogHelper
operator|::
name|hide
parameter_list|()
block|{
name|m_javaMessageDialog
operator|.
name|callMethod
argument_list|<
name|void
argument_list|>
argument_list|(
literal|"hide"
argument_list|,
literal|"()V"
argument_list|)
expr_stmt|;
name|m_shown
operator|=
literal|false
expr_stmt|;
block|}
DECL|function|dialogResult
name|void
name|QAndroidPlatformMessageDialogHelper
operator|::
name|dialogResult
parameter_list|(
name|int
name|buttonID
parameter_list|)
block|{
name|m_buttonId
operator|=
name|buttonID
expr_stmt|;
if|if
condition|(
name|m_loop
operator|.
name|isRunning
argument_list|()
condition|)
name|m_loop
operator|.
name|exit
argument_list|()
expr_stmt|;
if|if
condition|(
name|m_buttonId
operator|<
literal|0
condition|)
block|{
emit|emit
name|reject
argument_list|()
emit|;
return|return;
block|}
name|QPlatformDialogHelper
operator|::
name|StandardButton
name|standardButton
init|=
cast|static_cast
argument_list|<
name|QPlatformDialogHelper
operator|::
name|StandardButton
argument_list|>
argument_list|(
name|buttonID
argument_list|)
decl_stmt|;
name|QPlatformDialogHelper
operator|::
name|ButtonRole
name|role
init|=
name|QPlatformDialogHelper
operator|::
name|buttonRole
argument_list|(
name|standardButton
argument_list|)
decl_stmt|;
emit|emit
name|clicked
argument_list|(
name|standardButton
argument_list|,
name|role
argument_list|)
emit|;
block|}
DECL|function|dialogResult
specifier|static
name|void
name|dialogResult
parameter_list|(
name|JNIEnv
modifier|*
comment|/*env*/
parameter_list|,
name|jobject
comment|/*thiz*/
parameter_list|,
name|jlong
name|handler
parameter_list|,
name|int
name|buttonID
parameter_list|)
block|{
name|QObject
modifier|*
name|object
init|=
cast|reinterpret_cast
argument_list|<
name|QObject
operator|*
argument_list|>
argument_list|(
name|handler
argument_list|)
decl_stmt|;
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|object
argument_list|,
literal|"dialogResult"
argument_list|,
name|Qt
operator|::
name|QueuedConnection
argument_list|,
name|Q_ARG
argument_list|(
name|int
argument_list|,
name|buttonID
argument_list|)
argument_list|)
expr_stmt|;
block|}
DECL|member|methods
specifier|static
name|JNINativeMethod
name|methods
index|[]
init|=
block|{
block|{
literal|"dialogResult"
block|,
literal|"(JI)V"
block|,
operator|(
name|void
operator|*
operator|)
name|dialogResult
block|}
block|}
decl_stmt|;
DECL|macro|FIND_AND_CHECK_CLASS
define|#
directive|define
name|FIND_AND_CHECK_CLASS
parameter_list|(
name|CLASS_NAME
parameter_list|)
define|\
value|clazz = env->FindClass(CLASS_NAME); \     if (!clazz) { \         __android_log_print(ANDROID_LOG_FATAL, QtAndroid::qtTagText(), QtAndroid::classErrorMsgFmt(), CLASS_NAME); \         return false; \     }
DECL|function|registerNatives
name|bool
name|registerNatives
parameter_list|(
name|JNIEnv
modifier|*
name|env
parameter_list|)
block|{
name|jclass
name|clazz
init|=
name|QtAndroid
operator|::
name|findClass
argument_list|(
literal|"org.qtproject.qt5.android.QtMessageDialogHelper"
argument_list|,
name|env
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|clazz
condition|)
block|{
name|__android_log_print
argument_list|(
name|ANDROID_LOG_FATAL
argument_list|,
name|QtAndroid
operator|::
name|qtTagText
argument_list|()
argument_list|,
name|QtAndroid
operator|::
name|classErrorMsgFmt
argument_list|()
argument_list|,
literal|"org/qtproject/qt5/android/QtMessageDialogHelper"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|g_messageDialogHelperClass
operator|=
cast|static_cast
argument_list|<
name|jclass
argument_list|>
argument_list|(
name|env
operator|->
name|NewGlobalRef
argument_list|(
name|clazz
argument_list|)
argument_list|)
expr_stmt|;
name|FIND_AND_CHECK_CLASS
argument_list|(
literal|"org/qtproject/qt5/android/QtNativeDialogHelper"
argument_list|)
expr_stmt|;
name|jclass
name|appClass
init|=
cast|static_cast
argument_list|<
name|jclass
argument_list|>
argument_list|(
name|env
operator|->
name|NewGlobalRef
argument_list|(
name|clazz
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|env
operator|->
name|RegisterNatives
argument_list|(
name|appClass
argument_list|,
name|methods
argument_list|,
sizeof|sizeof
argument_list|(
name|methods
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|methods
index|[
literal|0
index|]
argument_list|)
argument_list|)
operator|<
literal|0
condition|)
block|{
name|__android_log_print
argument_list|(
name|ANDROID_LOG_FATAL
argument_list|,
literal|"Qt"
argument_list|,
literal|"RegisterNatives failed"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
return|return
literal|true
return|;
block|}
block|}
end_namespace
end_unit
