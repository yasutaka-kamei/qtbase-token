begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qxcbnativeinterfacehandler.h"
end_include
begin_include
include|#
directive|include
file|"qxcbnativeinterface.h"
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|QXcbNativeInterfaceHandler
name|QXcbNativeInterfaceHandler
operator|::
name|QXcbNativeInterfaceHandler
parameter_list|(
name|QXcbNativeInterface
modifier|*
name|nativeInterface
parameter_list|)
block|{
name|nativeInterface
operator|->
name|addHandler
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_function
begin_destructor
DECL|function|~QXcbNativeInterfaceHandler
name|QXcbNativeInterfaceHandler
operator|::
name|~
name|QXcbNativeInterfaceHandler
parameter_list|()
block|{
name|m_native_interface
operator|->
name|removeHandler
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|nativeResourceFunctionForIntegration
name|QPlatformNativeInterface
operator|::
name|NativeResourceForIntegrationFunction
name|QXcbNativeInterfaceHandler
operator|::
name|nativeResourceFunctionForIntegration
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|resource
parameter_list|)
specifier|const
block|{
name|Q_UNUSED
argument_list|(
name|resource
argument_list|)
expr_stmt|;
return|return
name|Q_NULLPTR
return|;
block|}
end_function
begin_function
DECL|function|nativeResourceFunctionForContext
name|QPlatformNativeInterface
operator|::
name|NativeResourceForContextFunction
name|QXcbNativeInterfaceHandler
operator|::
name|nativeResourceFunctionForContext
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|resource
parameter_list|)
specifier|const
block|{
name|Q_UNUSED
argument_list|(
name|resource
argument_list|)
expr_stmt|;
return|return
name|Q_NULLPTR
return|;
block|}
end_function
begin_function
DECL|function|nativeResourceFunctionForScreen
name|QPlatformNativeInterface
operator|::
name|NativeResourceForScreenFunction
name|QXcbNativeInterfaceHandler
operator|::
name|nativeResourceFunctionForScreen
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|resource
parameter_list|)
specifier|const
block|{
name|Q_UNUSED
argument_list|(
name|resource
argument_list|)
expr_stmt|;
return|return
name|Q_NULLPTR
return|;
block|}
end_function
begin_function
DECL|function|nativeResourceFunctionForWindow
name|QPlatformNativeInterface
operator|::
name|NativeResourceForWindowFunction
name|QXcbNativeInterfaceHandler
operator|::
name|nativeResourceFunctionForWindow
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|resource
parameter_list|)
specifier|const
block|{
name|Q_UNUSED
argument_list|(
name|resource
argument_list|)
expr_stmt|;
return|return
name|Q_NULLPTR
return|;
block|}
end_function
begin_function
DECL|function|nativeResourceFunctionForBackingStore
name|QPlatformNativeInterface
operator|::
name|NativeResourceForBackingStoreFunction
name|QXcbNativeInterfaceHandler
operator|::
name|nativeResourceFunctionForBackingStore
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|resource
parameter_list|)
specifier|const
block|{
name|Q_UNUSED
argument_list|(
name|resource
argument_list|)
expr_stmt|;
return|return
name|Q_NULLPTR
return|;
block|}
end_function
begin_function
DECL|function|platformFunction
name|QFunctionPointer
name|QXcbNativeInterfaceHandler
operator|::
name|platformFunction
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|function
parameter_list|)
specifier|const
block|{
name|Q_UNUSED
argument_list|(
name|function
argument_list|)
expr_stmt|;
return|return
name|Q_NULLPTR
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
