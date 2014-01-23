begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwindowsdirect2dcontext.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsdirect2dhelpers.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsdirect2ddevicecontext.h"
end_include
begin_include
include|#
directive|include
file|<wrl.h>
end_include
begin_using
using|using
name|Microsoft
operator|::
name|WRL
operator|::
name|ComPtr
using|;
end_using
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QWindowsDirect2DDeviceContextPrivate
class|class
name|QWindowsDirect2DDeviceContextPrivate
block|{
public|public:
DECL|function|QWindowsDirect2DDeviceContextPrivate
name|QWindowsDirect2DDeviceContextPrivate
parameter_list|(
name|ID2D1DeviceContext
modifier|*
name|dc
parameter_list|)
member_init_list|:
name|deviceContext
argument_list|(
name|dc
argument_list|)
member_init_list|,
name|refCount
argument_list|(
literal|0
argument_list|)
block|{
if|if
condition|(
operator|!
name|dc
condition|)
block|{
name|HRESULT
name|hr
init|=
name|QWindowsDirect2DContext
operator|::
name|instance
argument_list|()
operator|->
name|d2dDevice
argument_list|()
operator|->
name|CreateDeviceContext
argument_list|(
name|D2D1_DEVICE_CONTEXT_OPTIONS_NONE
argument_list|,
operator|&
name|deviceContext
argument_list|)
decl_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
name|qFatal
argument_list|(
literal|"%s: Couldn't create Direct2D Device Context: %#x"
argument_list|,
name|__FUNCTION__
argument_list|,
name|hr
argument_list|)
expr_stmt|;
block|}
name|Q_ASSERT
argument_list|(
name|deviceContext
argument_list|)
expr_stmt|;
block|}
DECL|function|begin
name|void
name|begin
parameter_list|()
block|{
name|Q_ASSERT
argument_list|(
name|deviceContext
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|refCount
operator|>=
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|refCount
operator|==
literal|0
condition|)
name|deviceContext
operator|->
name|BeginDraw
argument_list|()
expr_stmt|;
name|refCount
operator|++
expr_stmt|;
block|}
DECL|function|end
name|bool
name|end
parameter_list|()
block|{
name|Q_ASSERT
argument_list|(
name|deviceContext
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|refCount
operator|>
literal|0
argument_list|)
expr_stmt|;
name|bool
name|success
init|=
literal|true
decl_stmt|;
name|refCount
operator|--
expr_stmt|;
if|if
condition|(
name|refCount
operator|==
literal|0
condition|)
block|{
name|D2D1_TAG
name|tag1
decl_stmt|,
name|tag2
decl_stmt|;
name|HRESULT
name|hr
init|=
name|deviceContext
operator|->
name|EndDraw
argument_list|(
operator|&
name|tag1
argument_list|,
operator|&
name|tag2
argument_list|)
decl_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|hr
argument_list|)
condition|)
block|{
name|success
operator|=
literal|false
expr_stmt|;
name|qWarning
argument_list|(
literal|"%s: EndDraw failed: %#x, tag1: %lld, tag2: %lld"
argument_list|,
name|__FUNCTION__
argument_list|,
name|hr
argument_list|,
name|tag1
argument_list|,
name|tag2
argument_list|)
expr_stmt|;
block|}
block|}
return|return
name|success
return|;
block|}
DECL|member|deviceContext
name|ComPtr
argument_list|<
name|ID2D1DeviceContext
argument_list|>
name|deviceContext
decl_stmt|;
DECL|member|refCount
name|int
name|refCount
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|QWindowsDirect2DDeviceContext
name|QWindowsDirect2DDeviceContext
operator|::
name|QWindowsDirect2DDeviceContext
parameter_list|(
name|ID2D1DeviceContext
modifier|*
name|dc
parameter_list|)
member_init_list|:
name|d_ptr
argument_list|(
operator|new
name|QWindowsDirect2DDeviceContextPrivate
argument_list|(
name|dc
argument_list|)
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QWindowsDirect2DDeviceContext
name|QWindowsDirect2DDeviceContext
operator|::
name|~
name|QWindowsDirect2DDeviceContext
parameter_list|()
block|{  }
end_destructor
begin_function
DECL|function|get
name|ID2D1DeviceContext
modifier|*
name|QWindowsDirect2DDeviceContext
operator|::
name|get
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QWindowsDirect2DDeviceContext
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|d
operator|->
name|deviceContext
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|deviceContext
operator|.
name|Get
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|begin
name|void
name|QWindowsDirect2DDeviceContext
operator|::
name|begin
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QWindowsDirect2DDeviceContext
argument_list|)
expr_stmt|;
name|d
operator|->
name|begin
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|end
name|bool
name|QWindowsDirect2DDeviceContext
operator|::
name|end
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QWindowsDirect2DDeviceContext
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|end
argument_list|()
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
