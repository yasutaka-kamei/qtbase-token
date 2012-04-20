begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ** ** This file was generated by qdbusxml2cpp version 0.7 ** Command line was: qdbusxml2cpp -a car_adaptor.h: car.xml ** ** qdbusxml2cpp is Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** ** This is an auto-generated file. ** This file may have been hand-edited. Look for HAND-EDIT comments ** before re-generating it. ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|CAR_ADAPTOR_H_1264773009
end_ifndef
begin_define
DECL|macro|CAR_ADAPTOR_H_1264773009
define|#
directive|define
name|CAR_ADAPTOR_H_1264773009
end_define
begin_include
include|#
directive|include
file|<QtCore/QObject>
end_include
begin_include
include|#
directive|include
file|<QtDBus/QtDBus>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QByteArray
name|class
name|QByteArray
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|variable|QList
name|template
operator|<
name|class
name|T
operator|>
name|class
name|QList
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|variable|Key
DECL|variable|QMap
name|template
operator|<
name|class
name|Key
operator|,
name|class
name|Value
operator|>
name|class
name|QMap
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|QString
name|class
name|QString
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QStringList
name|class
name|QStringList
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QVariant
name|class
name|QVariant
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
comment|/*  * Adaptor class for interface org.example.Examples.CarInterface  */
name|class
name|CarInterfaceAdaptor
range|:
name|public
name|QDBusAbstractAdaptor
block|{
name|Q_OBJECT
name|Q_CLASSINFO
argument_list|(
literal|"D-Bus Interface"
argument_list|,
literal|"org.example.Examples.CarInterface"
argument_list|)
name|Q_CLASSINFO
argument_list|(
literal|"D-Bus Introspection"
argument_list|,
literal|""
literal|"<interface name=\"org.example.Examples.CarInterface\">\n"
literal|"<method name=\"accelerate\"/>\n"
literal|"<method name=\"decelerate\"/>\n"
literal|"<method name=\"turnLeft\"/>\n"
literal|"<method name=\"turnRight\"/>\n"
literal|"<signal name=\"crashed\"/>\n"
literal|"</interface>\n"
literal|""
argument_list|)
name|public
operator|:
name|CarInterfaceAdaptor
argument_list|(
name|QObject
operator|*
name|parent
argument_list|)
block|;
name|virtual
operator|~
name|CarInterfaceAdaptor
argument_list|()
block|;
name|public
operator|:
comment|// PROPERTIES
name|public
name|Q_SLOTS
operator|:
comment|// METHODS
name|void
name|accelerate
argument_list|()
block|;
name|void
name|decelerate
argument_list|()
block|;
name|void
name|turnLeft
argument_list|()
block|;
name|void
name|turnRight
argument_list|()
block|;
name|Q_SIGNALS
operator|:
comment|// SIGNALS
name|void
name|crashed
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
