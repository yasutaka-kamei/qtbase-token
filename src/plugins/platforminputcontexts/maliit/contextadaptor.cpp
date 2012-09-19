begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"contextadaptor.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QByteArray>
end_include
begin_include
include|#
directive|include
file|<QtCore/QList>
end_include
begin_include
include|#
directive|include
file|<QtCore/QMetaObject>
end_include
begin_include
include|#
directive|include
file|<QtCore/QMap>
end_include
begin_include
include|#
directive|include
file|<QtCore/QString>
end_include
begin_include
include|#
directive|include
file|<QtCore/QStringList>
end_include
begin_include
include|#
directive|include
file|<QtCore/QVariant>
end_include
begin_include
include|#
directive|include
file|"qmaliitplatforminputcontext.h"
end_include
begin_comment
comment|/*  * Implementation of adaptor class Inputcontext1Adaptor  */
end_comment
begin_constructor
DECL|function|Inputcontext1Adaptor
name|Inputcontext1Adaptor
operator|::
name|Inputcontext1Adaptor
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QDBusAbstractAdaptor
argument_list|(
name|parent
argument_list|)
block|{
comment|// constructor
name|setAutoRelaySignals
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~Inputcontext1Adaptor
name|Inputcontext1Adaptor
operator|::
name|~
name|Inputcontext1Adaptor
parameter_list|()
block|{
comment|// destructor
block|}
end_destructor
begin_function
DECL|function|activationLostEvent
name|void
name|Inputcontext1Adaptor
operator|::
name|activationLostEvent
parameter_list|()
block|{
comment|// handle method call com.meego.inputmethod.inputcontext1.activationLostEvent
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|parent
argument_list|()
argument_list|,
literal|"activationLostEvent"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|commitString
name|void
name|Inputcontext1Adaptor
operator|::
name|commitString
parameter_list|(
specifier|const
name|QString
modifier|&
name|in0
parameter_list|,
name|int
name|in1
parameter_list|,
name|int
name|in2
parameter_list|,
name|int
name|in3
parameter_list|)
block|{
comment|// handle method call com.meego.inputmethod.inputcontext1.commitString
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|parent
argument_list|()
argument_list|,
literal|"commitString"
argument_list|,
name|Q_ARG
argument_list|(
name|QString
argument_list|,
name|in0
argument_list|)
argument_list|,
name|Q_ARG
argument_list|(
name|int
argument_list|,
name|in1
argument_list|)
argument_list|,
name|Q_ARG
argument_list|(
name|int
argument_list|,
name|in2
argument_list|)
argument_list|,
name|Q_ARG
argument_list|(
name|int
argument_list|,
name|in3
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updatePreedit
name|void
name|Inputcontext1Adaptor
operator|::
name|updatePreedit
parameter_list|(
specifier|const
name|QDBusMessage
modifier|&
name|message
parameter_list|)
block|{
comment|// handle method call com.meego.inputmethod.inputcontext1.updatePreedit
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|parent
argument_list|()
argument_list|,
literal|"updatePreedit"
argument_list|,
name|Q_ARG
argument_list|(
name|QDBusMessage
argument_list|,
name|message
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|copy
name|void
name|Inputcontext1Adaptor
operator|::
name|copy
parameter_list|()
block|{
comment|// handle method call com.meego.inputmethod.inputcontext1.copy
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|parent
argument_list|()
argument_list|,
literal|"copy"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|imInitiatedHide
name|void
name|Inputcontext1Adaptor
operator|::
name|imInitiatedHide
parameter_list|()
block|{
comment|// handle method call com.meego.inputmethod.inputcontext1.imInitiatedHide
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|parent
argument_list|()
argument_list|,
literal|"imInitiatedHide"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|keyEvent
name|void
name|Inputcontext1Adaptor
operator|::
name|keyEvent
parameter_list|(
name|int
name|in0
parameter_list|,
name|int
name|in1
parameter_list|,
name|int
name|in2
parameter_list|,
specifier|const
name|QString
modifier|&
name|in3
parameter_list|,
name|bool
name|in4
parameter_list|,
name|int
name|in5
parameter_list|,
name|uchar
name|in6
parameter_list|)
block|{
comment|// handle method call com.meego.inputmethod.inputcontext1.keyEvent
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|parent
argument_list|()
argument_list|,
literal|"keyEvent"
argument_list|,
name|Q_ARG
argument_list|(
name|int
argument_list|,
name|in0
argument_list|)
argument_list|,
name|Q_ARG
argument_list|(
name|int
argument_list|,
name|in1
argument_list|)
argument_list|,
name|Q_ARG
argument_list|(
name|int
argument_list|,
name|in2
argument_list|)
argument_list|,
name|Q_ARG
argument_list|(
name|QString
argument_list|,
name|in3
argument_list|)
argument_list|,
name|Q_ARG
argument_list|(
name|bool
argument_list|,
name|in4
argument_list|)
argument_list|,
name|Q_ARG
argument_list|(
name|int
argument_list|,
name|in5
argument_list|)
argument_list|,
name|Q_ARG
argument_list|(
name|uchar
argument_list|,
name|in6
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|paste
name|void
name|Inputcontext1Adaptor
operator|::
name|paste
parameter_list|()
block|{
comment|// handle method call com.meego.inputmethod.inputcontext1.paste
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|parent
argument_list|()
argument_list|,
literal|"paste"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|preeditRectangle
name|bool
name|Inputcontext1Adaptor
operator|::
name|preeditRectangle
parameter_list|(
name|int
modifier|&
name|out1
parameter_list|,
name|int
modifier|&
name|out2
parameter_list|,
name|int
modifier|&
name|out3
parameter_list|,
name|int
modifier|&
name|out4
parameter_list|)
block|{
comment|// handle method call com.meego.inputmethod.inputcontext1.preeditRectangle
return|return
cast|static_cast
argument_list|<
name|QMaliitPlatformInputContext
operator|*
argument_list|>
argument_list|(
name|parent
argument_list|()
argument_list|)
operator|->
name|preeditRectangle
argument_list|(
name|out1
argument_list|,
name|out2
argument_list|,
name|out3
argument_list|,
name|out4
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|selection
name|bool
name|Inputcontext1Adaptor
operator|::
name|selection
parameter_list|(
name|QString
modifier|&
name|out1
parameter_list|)
block|{
comment|// handle method call com.meego.inputmethod.inputcontext1.selection
return|return
cast|static_cast
argument_list|<
name|QMaliitPlatformInputContext
operator|*
argument_list|>
argument_list|(
name|parent
argument_list|()
argument_list|)
operator|->
name|selection
argument_list|(
name|out1
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|setDetectableAutoRepeat
name|void
name|Inputcontext1Adaptor
operator|::
name|setDetectableAutoRepeat
parameter_list|(
name|bool
name|in0
parameter_list|)
block|{
comment|// handle method call com.meego.inputmethod.inputcontext1.setDetectableAutoRepeat
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|parent
argument_list|()
argument_list|,
literal|"setDetectableAutoRepeat"
argument_list|,
name|Q_ARG
argument_list|(
name|bool
argument_list|,
name|in0
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setGlobalCorrectionEnabled
name|void
name|Inputcontext1Adaptor
operator|::
name|setGlobalCorrectionEnabled
parameter_list|(
name|bool
name|in0
parameter_list|)
block|{
comment|// handle method call com.meego.inputmethod.inputcontext1.setGlobalCorrectionEnabled
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|parent
argument_list|()
argument_list|,
literal|"setGlobalCorrectionEnabled"
argument_list|,
name|Q_ARG
argument_list|(
name|bool
argument_list|,
name|in0
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setLanguage
name|void
name|Inputcontext1Adaptor
operator|::
name|setLanguage
parameter_list|(
specifier|const
name|QString
modifier|&
name|in0
parameter_list|)
block|{
comment|// handle method call com.meego.inputmethod.inputcontext1.setLanguage
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|parent
argument_list|()
argument_list|,
literal|"setLanguage"
argument_list|,
name|Q_ARG
argument_list|(
name|QString
argument_list|,
name|in0
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setRedirectKeys
name|void
name|Inputcontext1Adaptor
operator|::
name|setRedirectKeys
parameter_list|(
name|bool
name|in0
parameter_list|)
block|{
comment|// handle method call com.meego.inputmethod.inputcontext1.setRedirectKeys
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|parent
argument_list|()
argument_list|,
literal|"setRedirectKeys"
argument_list|,
name|Q_ARG
argument_list|(
name|bool
argument_list|,
name|in0
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setSelection
name|void
name|Inputcontext1Adaptor
operator|::
name|setSelection
parameter_list|(
name|int
name|in0
parameter_list|,
name|int
name|in1
parameter_list|)
block|{
comment|// handle method call com.meego.inputmethod.inputcontext1.setSelection
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|parent
argument_list|()
argument_list|,
literal|"setSelection"
argument_list|,
name|Q_ARG
argument_list|(
name|int
argument_list|,
name|in0
argument_list|)
argument_list|,
name|Q_ARG
argument_list|(
name|int
argument_list|,
name|in1
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updateInputMethodArea
name|void
name|Inputcontext1Adaptor
operator|::
name|updateInputMethodArea
parameter_list|(
name|int
name|in0
parameter_list|,
name|int
name|in1
parameter_list|,
name|int
name|in2
parameter_list|,
name|int
name|in3
parameter_list|)
block|{
comment|// handle method call com.meego.inputmethod.inputcontext1.updateInputMethodArea
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|parent
argument_list|()
argument_list|,
literal|"updateInputMethodArea"
argument_list|,
name|Q_ARG
argument_list|(
name|int
argument_list|,
name|in0
argument_list|)
argument_list|,
name|Q_ARG
argument_list|(
name|int
argument_list|,
name|in1
argument_list|)
argument_list|,
name|Q_ARG
argument_list|(
name|int
argument_list|,
name|in2
argument_list|)
argument_list|,
name|Q_ARG
argument_list|(
name|int
argument_list|,
name|in3
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
