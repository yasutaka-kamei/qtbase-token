begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qcupsprintersupport_p.h"
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformprintplugin.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QStringList>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PRINTER
end_ifndef
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QCupsPrinterSupportPlugin
class|class
name|QCupsPrinterSupportPlugin
super|:
specifier|public
name|QPlatformPrinterSupportPlugin
block|{
name|Q_OBJECT
name|Q_PLUGIN_METADATA
argument_list|(
name|IID
literal|"org.qt-project.QPlatformPrinterSupportFactoryInterface"
name|FILE
literal|"cups.json"
argument_list|)
decl|public
range|:
name|QStringList
name|keys
argument_list|()
specifier|const
decl_stmt|;
DECL|member|Q_DECL_OVERRIDE
name|QPlatformPrinterSupport
modifier|*
name|create
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|)
name|Q_DECL_OVERRIDE
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|keys
name|QStringList
name|QCupsPrinterSupportPlugin
operator|::
name|keys
parameter_list|()
specifier|const
block|{
return|return
name|QStringList
argument_list|(
name|QStringLiteral
argument_list|(
literal|"cupsprintersupport"
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|create
name|QPlatformPrinterSupport
modifier|*
name|QCupsPrinterSupportPlugin
operator|::
name|create
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|)
block|{
if|if
condition|(
name|key
operator|.
name|compare
argument_list|(
name|key
argument_list|,
name|QLatin1String
argument_list|(
literal|"cupsprintersupport"
argument_list|)
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|new
name|QCupsPrinterSupport
return|;
return|return
literal|0
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_PRINTER
end_comment
begin_include
include|#
directive|include
file|"main.moc"
end_include
end_unit
