begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Jeremy LainÃ©<jeremy.laine@m4x.org> ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"dnslookup.h"
end_include
begin_include
include|#
directive|include
file|<QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QDnsLookup>
end_include
begin_include
include|#
directive|include
file|<QHostAddress>
end_include
begin_include
include|#
directive|include
file|<QStringList>
end_include
begin_include
include|#
directive|include
file|<QTimer>
end_include
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_function
DECL|function|usage
specifier|static
name|void
name|usage
parameter_list|()
block|{
name|printf
argument_list|(
literal|"Qt DNS example - performs DNS lookups\n"
literal|"Usage: dnslookup [-t<type>] [-s nameserver] name\n\n"
argument_list|)
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|DnsManager
name|DnsManager
operator|::
name|DnsManager
parameter_list|()
block|{
name|dns
operator|=
operator|new
name|QDnsLookup
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|dns
argument_list|,
name|SIGNAL
argument_list|(
name|finished
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|showResults
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|execute
name|void
name|DnsManager
operator|::
name|execute
parameter_list|()
block|{
name|QStringList
name|args
init|=
name|QCoreApplication
operator|::
name|instance
argument_list|()
operator|->
name|arguments
argument_list|()
decl_stmt|;
name|args
operator|.
name|takeFirst
argument_list|()
expr_stmt|;
comment|// lookup type
name|dns
operator|->
name|setType
argument_list|(
name|QDnsLookup
operator|::
name|A
argument_list|)
expr_stmt|;
if|if
condition|(
name|args
operator|.
name|size
argument_list|()
operator|>
literal|1
operator|&&
name|args
operator|.
name|first
argument_list|()
operator|==
literal|"-t"
condition|)
block|{
name|args
operator|.
name|takeFirst
argument_list|()
expr_stmt|;
specifier|const
name|QString
name|type
init|=
name|args
operator|.
name|takeFirst
argument_list|()
operator|.
name|toLower
argument_list|()
decl_stmt|;
if|if
condition|(
name|type
operator|==
literal|"a"
condition|)
name|dns
operator|->
name|setType
argument_list|(
name|QDnsLookup
operator|::
name|A
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|type
operator|==
literal|"aaaa"
condition|)
name|dns
operator|->
name|setType
argument_list|(
name|QDnsLookup
operator|::
name|AAAA
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|type
operator|==
literal|"any"
condition|)
name|dns
operator|->
name|setType
argument_list|(
name|QDnsLookup
operator|::
name|ANY
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|type
operator|==
literal|"cname"
condition|)
name|dns
operator|->
name|setType
argument_list|(
name|QDnsLookup
operator|::
name|CNAME
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|type
operator|==
literal|"mx"
condition|)
name|dns
operator|->
name|setType
argument_list|(
name|QDnsLookup
operator|::
name|MX
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|type
operator|==
literal|"ns"
condition|)
name|dns
operator|->
name|setType
argument_list|(
name|QDnsLookup
operator|::
name|NS
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|type
operator|==
literal|"ptr"
condition|)
name|dns
operator|->
name|setType
argument_list|(
name|QDnsLookup
operator|::
name|PTR
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|type
operator|==
literal|"srv"
condition|)
name|dns
operator|->
name|setType
argument_list|(
name|QDnsLookup
operator|::
name|SRV
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|type
operator|==
literal|"txt"
condition|)
name|dns
operator|->
name|setType
argument_list|(
name|QDnsLookup
operator|::
name|TXT
argument_list|)
expr_stmt|;
else|else
block|{
name|printf
argument_list|(
literal|"Bad record type: %s\n"
argument_list|,
name|qPrintable
argument_list|(
name|type
argument_list|)
argument_list|)
expr_stmt|;
name|QCoreApplication
operator|::
name|instance
argument_list|()
operator|->
name|quit
argument_list|()
expr_stmt|;
return|return;
block|}
block|}
if|if
condition|(
name|args
operator|.
name|size
argument_list|()
operator|>
literal|1
operator|&&
name|args
operator|.
name|first
argument_list|()
operator|==
literal|"-s"
condition|)
block|{
name|args
operator|.
name|takeFirst
argument_list|()
expr_stmt|;
specifier|const
name|QString
name|ns
init|=
name|args
operator|.
name|takeFirst
argument_list|()
decl_stmt|;
name|QHostAddress
name|nameserver
argument_list|(
name|ns
argument_list|)
decl_stmt|;
if|if
condition|(
name|nameserver
operator|.
name|isNull
argument_list|()
operator|||
name|nameserver
operator|.
name|protocol
argument_list|()
operator|==
name|QAbstractSocket
operator|::
name|UnknownNetworkLayerProtocol
condition|)
block|{
name|printf
argument_list|(
literal|"Bad nameserver address: %s\n"
argument_list|,
name|qPrintable
argument_list|(
name|ns
argument_list|)
argument_list|)
expr_stmt|;
name|QCoreApplication
operator|::
name|instance
argument_list|()
operator|->
name|quit
argument_list|()
expr_stmt|;
return|return;
block|}
name|dns
operator|->
name|setNameserver
argument_list|(
name|nameserver
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|args
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|usage
argument_list|()
expr_stmt|;
name|QCoreApplication
operator|::
name|instance
argument_list|()
operator|->
name|quit
argument_list|()
expr_stmt|;
return|return;
block|}
name|dns
operator|->
name|setName
argument_list|(
name|args
operator|.
name|takeFirst
argument_list|()
argument_list|)
expr_stmt|;
name|dns
operator|->
name|lookup
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|showResults
name|void
name|DnsManager
operator|::
name|showResults
parameter_list|()
block|{
if|if
condition|(
name|dns
operator|->
name|error
argument_list|()
operator|!=
name|QDnsLookup
operator|::
name|NoError
condition|)
name|printf
argument_list|(
literal|"Error: %i (%s)\n"
argument_list|,
name|dns
operator|->
name|error
argument_list|()
argument_list|,
name|qPrintable
argument_list|(
name|dns
operator|->
name|errorString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|// CNAME records
foreach|foreach
control|(
specifier|const
name|QDnsDomainNameRecord
modifier|&
name|record
decl|,
name|dns
operator|->
name|canonicalNameRecords
argument_list|()
control|)
name|printf
argument_list|(
literal|"%s\t%i\tIN\tCNAME\t%s\n"
argument_list|,
name|qPrintable
argument_list|(
name|record
operator|.
name|name
argument_list|()
argument_list|)
argument_list|,
name|record
operator|.
name|timeToLive
argument_list|()
argument_list|,
name|qPrintable
argument_list|(
name|record
operator|.
name|value
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|// A and AAAA records
foreach|foreach
control|(
specifier|const
name|QDnsHostAddressRecord
modifier|&
name|record
decl|,
name|dns
operator|->
name|hostAddressRecords
argument_list|()
control|)
block|{
specifier|const
name|char
modifier|*
name|type
init|=
operator|(
name|record
operator|.
name|value
argument_list|()
operator|.
name|protocol
argument_list|()
operator|==
name|QAbstractSocket
operator|::
name|IPv6Protocol
operator|)
condition|?
literal|"AAAA"
else|:
literal|"A"
decl_stmt|;
name|printf
argument_list|(
literal|"%s\t%i\tIN\t%s\t%s\n"
argument_list|,
name|qPrintable
argument_list|(
name|record
operator|.
name|name
argument_list|()
argument_list|)
argument_list|,
name|record
operator|.
name|timeToLive
argument_list|()
argument_list|,
name|type
argument_list|,
name|qPrintable
argument_list|(
name|record
operator|.
name|value
argument_list|()
operator|.
name|toString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|// MX records
foreach|foreach
control|(
specifier|const
name|QDnsMailExchangeRecord
modifier|&
name|record
decl|,
name|dns
operator|->
name|mailExchangeRecords
argument_list|()
control|)
name|printf
argument_list|(
literal|"%s\t%i\tIN\tMX\t%u %s\n"
argument_list|,
name|qPrintable
argument_list|(
name|record
operator|.
name|name
argument_list|()
argument_list|)
argument_list|,
name|record
operator|.
name|timeToLive
argument_list|()
argument_list|,
name|record
operator|.
name|preference
argument_list|()
argument_list|,
name|qPrintable
argument_list|(
name|record
operator|.
name|exchange
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|// NS records
foreach|foreach
control|(
specifier|const
name|QDnsDomainNameRecord
modifier|&
name|record
decl|,
name|dns
operator|->
name|nameServerRecords
argument_list|()
control|)
name|printf
argument_list|(
literal|"%s\t%i\tIN\tNS\t%s\n"
argument_list|,
name|qPrintable
argument_list|(
name|record
operator|.
name|name
argument_list|()
argument_list|)
argument_list|,
name|record
operator|.
name|timeToLive
argument_list|()
argument_list|,
name|qPrintable
argument_list|(
name|record
operator|.
name|value
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|// PTR records
foreach|foreach
control|(
specifier|const
name|QDnsDomainNameRecord
modifier|&
name|record
decl|,
name|dns
operator|->
name|pointerRecords
argument_list|()
control|)
name|printf
argument_list|(
literal|"%s\t%i\tIN\tPTR\t%s\n"
argument_list|,
name|qPrintable
argument_list|(
name|record
operator|.
name|name
argument_list|()
argument_list|)
argument_list|,
name|record
operator|.
name|timeToLive
argument_list|()
argument_list|,
name|qPrintable
argument_list|(
name|record
operator|.
name|value
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|// SRV records
foreach|foreach
control|(
specifier|const
name|QDnsServiceRecord
modifier|&
name|record
decl|,
name|dns
operator|->
name|serviceRecords
argument_list|()
control|)
name|printf
argument_list|(
literal|"%s\t%i\tIN\tSRV\t%u %u %u %s\n"
argument_list|,
name|qPrintable
argument_list|(
name|record
operator|.
name|name
argument_list|()
argument_list|)
argument_list|,
name|record
operator|.
name|timeToLive
argument_list|()
argument_list|,
name|record
operator|.
name|priority
argument_list|()
argument_list|,
name|record
operator|.
name|weight
argument_list|()
argument_list|,
name|record
operator|.
name|port
argument_list|()
argument_list|,
name|qPrintable
argument_list|(
name|record
operator|.
name|target
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|// TXT records
foreach|foreach
control|(
specifier|const
name|QDnsTextRecord
modifier|&
name|record
decl|,
name|dns
operator|->
name|textRecords
argument_list|()
control|)
block|{
name|QStringList
name|values
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QByteArray
modifier|&
name|ba
decl|,
name|record
operator|.
name|values
argument_list|()
control|)
name|values
operator|<<
literal|"\""
operator|+
name|QString
operator|::
name|fromLatin1
argument_list|(
name|ba
argument_list|)
operator|+
literal|"\""
expr_stmt|;
name|printf
argument_list|(
literal|"%s\t%i\tIN\tTXT\t%s\n"
argument_list|,
name|qPrintable
argument_list|(
name|record
operator|.
name|name
argument_list|()
argument_list|)
argument_list|,
name|record
operator|.
name|timeToLive
argument_list|()
argument_list|,
name|qPrintable
argument_list|(
name|values
operator|.
name|join
argument_list|(
literal|' '
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|QCoreApplication
operator|::
name|instance
argument_list|()
operator|->
name|quit
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|QCoreApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|DnsManager
name|manager
decl_stmt|;
name|QTimer
operator|::
name|singleShot
argument_list|(
literal|0
argument_list|,
operator|&
name|manager
argument_list|,
name|SLOT
argument_list|(
name|execute
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|app
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
end_unit
