begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qdnslookup_p.h"
end_include
begin_include
include|#
directive|include
file|<qurl.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<wrl.h>
end_include
begin_include
include|#
directive|include
file|<windows.foundation.h>
end_include
begin_include
include|#
directive|include
file|<windows.foundation.collections.h>
end_include
begin_include
include|#
directive|include
file|<windows.networking.h>
end_include
begin_include
include|#
directive|include
file|<windows.networking.sockets.h>
end_include
begin_using
using|using
namespace|namespace
name|Microsoft
operator|::
name|WRL
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|Microsoft
operator|::
name|WRL
operator|::
name|Wrappers
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|ABI
operator|::
name|Windows
operator|::
name|Foundation
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|ABI
operator|::
name|Windows
operator|::
name|Foundation
operator|::
name|Collections
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|ABI
operator|::
name|Windows
operator|::
name|Networking
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|ABI
operator|::
name|Windows
operator|::
name|Networking
operator|::
name|Connectivity
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|ABI
operator|::
name|Windows
operator|::
name|Networking
operator|::
name|Sockets
namespace|;
end_using
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|query
name|void
name|QDnsLookupRunnable
operator|::
name|query
parameter_list|(
specifier|const
name|int
name|requestType
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|requestName
parameter_list|,
specifier|const
name|QHostAddress
modifier|&
name|nameserver
parameter_list|,
name|QDnsLookupReply
modifier|*
name|reply
parameter_list|)
block|{
comment|// TODO: Add nameserver support for winRT
if|if
condition|(
operator|!
name|nameserver
operator|.
name|isNull
argument_list|()
condition|)
name|qWarning
argument_list|()
operator|<<
literal|"Ignoring nameserver as its currently not supported on WinRT"
expr_stmt|;
comment|// TODO: is there any way to do "proper" dns lookup?
if|if
condition|(
name|requestType
operator|!=
name|QDnsLookup
operator|::
name|A
operator|&&
name|requestType
operator|!=
name|QDnsLookup
operator|::
name|AAAA
operator|&&
name|requestType
operator|!=
name|QDnsLookup
operator|::
name|ANY
condition|)
block|{
name|reply
operator|->
name|error
operator|=
name|QDnsLookup
operator|::
name|InvalidRequestError
expr_stmt|;
name|reply
operator|->
name|errorString
operator|=
name|QLatin1String
argument_list|(
literal|"WinRT only supports IPv4 and IPv6 requests"
argument_list|)
expr_stmt|;
return|return;
block|}
name|QString
name|aceHostname
init|=
name|QUrl
operator|::
name|fromAce
argument_list|(
name|requestName
argument_list|)
decl_stmt|;
if|if
condition|(
name|aceHostname
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|reply
operator|->
name|error
operator|=
name|QDnsLookup
operator|::
name|InvalidRequestError
expr_stmt|;
name|reply
operator|->
name|errorString
operator|=
name|requestName
operator|.
name|isEmpty
argument_list|()
condition|?
name|tr
argument_list|(
literal|"No hostname given"
argument_list|)
else|:
name|tr
argument_list|(
literal|"Invalid hostname"
argument_list|)
expr_stmt|;
return|return;
block|}
name|IHostNameFactory
modifier|*
name|hostnameFactory
decl_stmt|;
name|HStringReference
name|classId
argument_list|(
name|RuntimeClass_Windows_Networking_HostName
argument_list|)
decl_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|GetActivationFactory
argument_list|(
name|classId
operator|.
name|Get
argument_list|()
argument_list|,
operator|&
name|hostnameFactory
argument_list|)
argument_list|)
condition|)
block|{
name|reply
operator|->
name|error
operator|=
name|QDnsLookup
operator|::
name|ResolverError
expr_stmt|;
name|reply
operator|->
name|errorString
operator|=
name|QLatin1String
argument_list|(
literal|"Could not obtain hostname factory"
argument_list|)
expr_stmt|;
return|return;
block|}
name|IHostName
modifier|*
name|host
decl_stmt|;
name|HStringReference
name|hostNameRef
argument_list|(
operator|(
specifier|const
name|wchar_t
operator|*
operator|)
name|aceHostname
operator|.
name|utf16
argument_list|()
argument_list|)
decl_stmt|;
name|hostnameFactory
operator|->
name|CreateHostName
argument_list|(
name|hostNameRef
operator|.
name|Get
argument_list|()
argument_list|,
operator|&
name|host
argument_list|)
expr_stmt|;
name|hostnameFactory
operator|->
name|Release
argument_list|()
expr_stmt|;
name|IDatagramSocketStatics
modifier|*
name|datagramSocketStatics
decl_stmt|;
name|GetActivationFactory
argument_list|(
name|HString
operator|::
name|MakeReference
argument_list|(
name|RuntimeClass_Windows_Networking_Sockets_DatagramSocket
argument_list|)
operator|.
name|Get
argument_list|()
argument_list|,
operator|&
name|datagramSocketStatics
argument_list|)
expr_stmt|;
name|IAsyncOperation
argument_list|<
name|IVectorView
argument_list|<
name|EndpointPair
modifier|*
argument_list|>
modifier|*
argument_list|>
modifier|*
name|op
decl_stmt|;
name|HSTRING
name|proto
decl_stmt|;
name|WindowsCreateString
argument_list|(
literal|L"0"
argument_list|,
literal|1
argument_list|,
operator|&
name|proto
argument_list|)
expr_stmt|;
name|datagramSocketStatics
operator|->
name|GetEndpointPairsAsync
argument_list|(
name|host
argument_list|,
name|proto
argument_list|,
operator|&
name|op
argument_list|)
expr_stmt|;
name|datagramSocketStatics
operator|->
name|Release
argument_list|()
expr_stmt|;
name|host
operator|->
name|Release
argument_list|()
expr_stmt|;
name|IVectorView
argument_list|<
name|EndpointPair
modifier|*
argument_list|>
modifier|*
name|endpointPairs
init|=
literal|0
decl_stmt|;
name|HRESULT
name|hr
init|=
name|op
operator|->
name|GetResults
argument_list|(
operator|&
name|endpointPairs
argument_list|)
decl_stmt|;
name|int
name|waitCount
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|hr
operator|==
name|E_ILLEGAL_METHOD_CALL
condition|)
block|{
name|WaitForSingleObjectEx
argument_list|(
name|GetCurrentThread
argument_list|()
argument_list|,
literal|50
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
name|hr
operator|=
name|op
operator|->
name|GetResults
argument_list|(
operator|&
name|endpointPairs
argument_list|)
expr_stmt|;
if|if
condition|(
operator|++
name|waitCount
operator|>
literal|1200
condition|)
comment|// Wait for 1 minute max
return|return;
block|}
name|op
operator|->
name|Release
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|endpointPairs
condition|)
return|return;
name|unsigned
name|int
name|size
decl_stmt|;
name|endpointPairs
operator|->
name|get_Size
argument_list|(
operator|&
name|size
argument_list|)
expr_stmt|;
for|for
control|(
name|unsigned
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|size
condition|;
operator|++
name|i
control|)
block|{
name|IEndpointPair
modifier|*
name|endpointpair
decl_stmt|;
name|endpointPairs
operator|->
name|GetAt
argument_list|(
name|i
argument_list|,
operator|&
name|endpointpair
argument_list|)
expr_stmt|;
name|IHostName
modifier|*
name|remoteHost
decl_stmt|;
name|endpointpair
operator|->
name|get_RemoteHostName
argument_list|(
operator|&
name|remoteHost
argument_list|)
expr_stmt|;
name|endpointpair
operator|->
name|Release
argument_list|()
expr_stmt|;
name|HostNameType
name|type
decl_stmt|;
name|remoteHost
operator|->
name|get_Type
argument_list|(
operator|&
name|type
argument_list|)
expr_stmt|;
if|if
condition|(
name|type
operator|==
name|HostNameType_Bluetooth
operator|||
name|type
operator|==
name|HostNameType_DomainName
operator|||
operator|(
name|requestType
operator|!=
name|QDnsLookup
operator|::
name|ANY
operator|&&
operator|(
operator|(
name|type
operator|==
name|HostNameType_Ipv4
operator|&&
name|requestType
operator|==
name|QDnsLookup
operator|::
name|AAAA
operator|)
operator|||
operator|(
name|type
operator|==
name|HostNameType_Ipv6
operator|&&
name|requestType
operator|==
name|QDnsLookup
operator|::
name|A
operator|)
operator|)
operator|)
condition|)
continue|continue;
name|HSTRING
name|name
decl_stmt|;
name|remoteHost
operator|->
name|get_CanonicalName
argument_list|(
operator|&
name|name
argument_list|)
expr_stmt|;
name|remoteHost
operator|->
name|Release
argument_list|()
expr_stmt|;
name|UINT32
name|length
decl_stmt|;
name|PCWSTR
name|rawString
init|=
name|WindowsGetStringRawBuffer
argument_list|(
name|name
argument_list|,
operator|&
name|length
argument_list|)
decl_stmt|;
name|QDnsHostAddressRecord
name|record
decl_stmt|;
name|record
operator|.
name|d
operator|->
name|name
operator|=
name|aceHostname
expr_stmt|;
name|record
operator|.
name|d
operator|->
name|value
operator|=
name|QHostAddress
argument_list|(
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|rawString
argument_list|,
name|length
argument_list|)
argument_list|)
expr_stmt|;
name|reply
operator|->
name|hostAddressRecords
operator|.
name|append
argument_list|(
name|record
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
