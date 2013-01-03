begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtTest module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSIGNALSPY_H
end_ifndef
begin_define
DECL|macro|QSIGNALSPY_H
define|#
directive|define
name|QSIGNALSPY_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qbytearray.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlist.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmetaobject.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvariant.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvector.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/qtesteventloop.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QVariant
name|class
name|QVariant
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QObject
name|class
name|QSignalSpy
range|:
name|public
name|QObject
decl_stmt|,
name|public
name|QList
decl|<
name|QList
decl|<
name|QVariant
decl|>>
block|{
name|public
label|:
name|explicit
name|QSignalSpy
argument_list|(
specifier|const
name|QObject
operator|*
name|obj
argument_list|,
specifier|const
name|char
operator|*
name|aSignal
argument_list|)
operator|:
name|m_waiting
argument_list|(
argument|false
argument_list|)
block|{
ifdef|#
directive|ifdef
name|Q_CC_BOR
specifier|const
name|int
name|memberOffset
operator|=
name|QObject
operator|::
name|staticMetaObject
operator|.
name|methodCount
argument_list|()
block|;
else|#
directive|else
specifier|static
specifier|const
name|int
name|memberOffset
operator|=
name|QObject
operator|::
name|staticMetaObject
operator|.
name|methodCount
argument_list|()
block|;
endif|#
directive|endif
if|if
condition|(
operator|!
name|obj
condition|)
block|{
name|qWarning
argument_list|(
literal|"QSignalSpy: Cannot spy on a null object"
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
operator|!
name|aSignal
condition|)
block|{
name|qWarning
argument_list|(
literal|"QSignalSpy: Null signal name is not valid"
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
operator|(
operator|(
name|aSignal
index|[
literal|0
index|]
operator|-
literal|'0'
operator|)
operator|&
literal|0x03
operator|)
operator|!=
name|QSIGNAL_CODE
condition|)
block|{
name|qWarning
argument_list|(
literal|"QSignalSpy: Not a valid signal, use the SIGNAL macro"
argument_list|)
expr_stmt|;
return|return;
block|}
specifier|const
name|QByteArray
name|ba
init|=
name|QMetaObject
operator|::
name|normalizedSignature
argument_list|(
name|aSignal
operator|+
literal|1
argument_list|)
decl_stmt|;
specifier|const
name|QMetaObject
operator|*
specifier|const
name|mo
operator|=
name|obj
operator|->
name|metaObject
argument_list|()
expr_stmt|;
specifier|const
name|int
name|sigIndex
init|=
name|mo
operator|->
name|indexOfMethod
argument_list|(
name|ba
operator|.
name|constData
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|sigIndex
operator|<
literal|0
condition|)
block|{
name|qWarning
argument_list|(
literal|"QSignalSpy: No such signal: '%s'"
argument_list|,
name|ba
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
operator|!
name|QMetaObject
operator|::
name|connect
argument_list|(
name|obj
argument_list|,
name|sigIndex
argument_list|,
name|this
argument_list|,
name|memberOffset
argument_list|,
name|Qt
operator|::
name|DirectConnection
argument_list|,
literal|0
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"QSignalSpy: QMetaObject::connect returned false. Unable to connect."
argument_list|)
expr_stmt|;
return|return;
block|}
name|sig
operator|=
name|ba
expr_stmt|;
name|initArgs
argument_list|(
name|mo
operator|->
name|method
argument_list|(
name|sigIndex
argument_list|)
argument_list|,
name|obj
argument_list|)
expr_stmt|;
block|}
end_decl_stmt
begin_expr_stmt
specifier|inline
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
operator|!
name|sig
operator|.
name|isEmpty
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QByteArray
name|signal
argument_list|()
specifier|const
block|{
return|return
name|sig
return|;
block|}
end_expr_stmt
begin_function
name|bool
name|wait
parameter_list|(
name|int
name|timeout
init|=
literal|5000
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
operator|!
name|m_waiting
argument_list|)
expr_stmt|;
specifier|const
name|int
name|origCount
init|=
name|count
argument_list|()
decl_stmt|;
name|m_waiting
operator|=
name|true
expr_stmt|;
name|m_loop
operator|.
name|enterLoopMSecs
argument_list|(
name|timeout
argument_list|)
expr_stmt|;
name|m_waiting
operator|=
name|false
expr_stmt|;
return|return
name|count
argument_list|()
operator|>
name|origCount
return|;
block|}
end_function
begin_decl_stmt
name|int
name|qt_metacall
argument_list|(
name|QMetaObject
operator|::
name|Call
name|call
argument_list|,
name|int
name|methodId
argument_list|,
name|void
operator|*
operator|*
name|a
argument_list|)
name|Q_DECL_OVERRIDE
block|{
name|methodId
operator|=
name|QObject
operator|::
name|qt_metacall
argument_list|(
name|call
argument_list|,
name|methodId
argument_list|,
name|a
argument_list|)
expr_stmt|;
if|if
condition|(
name|methodId
operator|<
literal|0
condition|)
return|return
name|methodId
return|;
if|if
condition|(
name|call
operator|==
name|QMetaObject
operator|::
name|InvokeMetaMethod
condition|)
block|{
if|if
condition|(
name|methodId
operator|==
literal|0
condition|)
block|{
name|appendArgs
argument_list|(
name|a
argument_list|)
expr_stmt|;
block|}
operator|--
name|methodId
expr_stmt|;
block|}
return|return
name|methodId
return|;
block|}
end_decl_stmt
begin_label
name|private
label|:
end_label
begin_function
name|void
name|initArgs
parameter_list|(
specifier|const
name|QMetaMethod
modifier|&
name|member
parameter_list|)
block|{
name|initArgs
argument_list|(
name|member
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
name|void
name|initArgs
parameter_list|(
specifier|const
name|QMetaMethod
modifier|&
name|member
parameter_list|,
specifier|const
name|QObject
modifier|*
name|obj
parameter_list|)
block|{
specifier|const
name|QList
operator|<
name|QByteArray
operator|>
name|params
operator|=
name|member
operator|.
name|parameterTypes
argument_list|()
expr_stmt|;
name|args
operator|.
name|reserve
argument_list|(
name|params
operator|.
name|size
argument_list|()
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
name|params
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|int
name|tp
init|=
name|QMetaType
operator|::
name|type
argument_list|(
name|params
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|constData
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|tp
operator|==
name|QMetaType
operator|::
name|UnknownType
operator|&&
name|obj
condition|)
block|{
name|void
modifier|*
name|argv
index|[]
init|=
block|{
operator|&
name|tp
block|,
operator|&
name|i
block|}
decl_stmt|;
name|QMetaObject
operator|::
name|metacall
argument_list|(
name|const_cast
operator|<
name|QObject
operator|*
operator|>
operator|(
name|obj
operator|)
argument_list|,
name|QMetaObject
operator|::
name|RegisterMethodArgumentMetaType
argument_list|,
name|member
operator|.
name|methodIndex
argument_list|()
argument_list|,
name|argv
argument_list|)
expr_stmt|;
if|if
condition|(
name|tp
operator|==
operator|-
literal|1
condition|)
name|tp
operator|=
name|QMetaType
operator|::
name|UnknownType
expr_stmt|;
block|}
if|if
condition|(
name|tp
operator|==
name|QMetaType
operator|::
name|UnknownType
condition|)
block|{
name|Q_ASSERT
argument_list|(
name|tp
operator|!=
name|QMetaType
operator|::
name|Void
argument_list|)
expr_stmt|;
comment|// void parameter => metaobject is corrupt
name|qWarning
argument_list|(
literal|"Don't know how to handle '%s', use qRegisterMetaType to register it."
argument_list|,
name|params
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|args
operator|<<
name|tp
expr_stmt|;
block|}
block|}
end_function
begin_function
name|void
name|appendArgs
parameter_list|(
name|void
modifier|*
modifier|*
name|a
parameter_list|)
block|{
name|QList
operator|<
name|QVariant
operator|>
name|list
expr_stmt|;
name|list
operator|.
name|reserve
argument_list|(
name|args
operator|.
name|count
argument_list|()
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
name|args
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|QMetaType
operator|::
name|Type
name|type
operator|=
name|static_cast
operator|<
name|QMetaType
operator|::
name|Type
operator|>
operator|(
name|args
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|)
expr_stmt|;
if|if
condition|(
name|type
operator|==
name|QMetaType
operator|::
name|QVariant
condition|)
name|list
operator|<<
operator|*
name|reinterpret_cast
operator|<
name|QVariant
operator|*
operator|>
operator|(
name|a
index|[
name|i
operator|+
literal|1
index|]
operator|)
expr_stmt|;
else|else
name|list
operator|<<
name|QVariant
argument_list|(
name|type
argument_list|,
name|a
index|[
name|i
operator|+
literal|1
index|]
argument_list|)
expr_stmt|;
block|}
name|append
argument_list|(
name|list
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_waiting
condition|)
name|m_loop
operator|.
name|exitLoop
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|// the full, normalized signal name
end_comment
begin_decl_stmt
name|QByteArray
name|sig
decl_stmt|;
end_decl_stmt
begin_comment
comment|// holds the QMetaType types for the argument list of the signal
end_comment
begin_expr_stmt
name|QVector
operator|<
name|int
operator|>
name|args
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QTestEventLoop
name|m_loop
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|m_waiting
decl_stmt|;
end_decl_stmt
begin_expr_stmt
unit|};
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
