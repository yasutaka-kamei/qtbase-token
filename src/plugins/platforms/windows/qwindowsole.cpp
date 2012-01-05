begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwindowsole.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsmime.h"
end_include
begin_include
include|#
directive|include
file|"qwindowscontext.h"
end_include
begin_expr_stmt
unit|\
operator|#
name|include
argument_list|<
name|QtGui
operator|/
name|QMouseEvent
argument_list|>
include|#
directive|include
file|<QtGui/QWindow>
include|#
directive|include
file|<QtGui/QPainter>
include|#
directive|include
file|<QtGui/QCursor>
include|#
directive|include
file|<QtGui/QGuiApplication>
include|#
directive|include
file|<QtCore/QMimeData>
include|#
directive|include
file|<QtCore/QDebug>
include|#
directive|include
file|<shlobj.h>
name|QT_BEGIN_NAMESPACE
comment|/*!     \class QWindowsOleDataObject     \brief OLE data container     The following methods are NOT supported for data transfer using the    clipboard or drag-drop:    \list    \o IDataObject::SetData    -- return E_NOTIMPL    \o IDataObject::DAdvise    -- return OLE_E_ADVISENOTSUPPORTED    \o ::DUnadvise    \o ::EnumDAdvise    \o IDataObject::GetCanonicalFormatEtc -- return E_NOTIMPL        (NOTE: must set pformatetcOut->ptd = NULL)    \endlist      \ingroup qt-lighthouse-win */
DECL|function|QWindowsOleDataObject
name|QWindowsOleDataObject
operator|::
name|QWindowsOleDataObject
argument_list|(
name|QMimeData
operator|*
name|mimeData
argument_list|)
operator|:
name|m_refs
argument_list|(
literal|1
argument_list|)
operator|,
name|data
argument_list|(
name|mimeData
argument_list|)
operator|,
name|CF_PERFORMEDDROPEFFECT
argument_list|(
name|RegisterClipboardFormat
argument_list|(
name|CFSTR_PERFORMEDDROPEFFECT
argument_list|)
argument_list|)
operator|,
name|performedEffect
argument_list|(
argument|DROPEFFECT_NONE
argument_list|)
block|{
if|if
condition|(
name|QWindowsContext
operator|::
name|verboseOLE
condition|)
name|qDebug
argument_list|(
literal|"%s '%s'"
argument_list|,
name|__FUNCTION__
argument_list|,
name|qPrintable
argument_list|(
name|mimeData
operator|->
name|formats
argument_list|()
operator|.
name|join
argument_list|(
name|QStringLiteral
argument_list|(
literal|", "
argument_list|)
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_destructor
DECL|function|~QWindowsOleDataObject
name|QWindowsOleDataObject
operator|::
name|~
name|QWindowsOleDataObject
parameter_list|()
block|{
if|if
condition|(
name|QWindowsContext
operator|::
name|verboseOLE
condition|)
name|qDebug
argument_list|(
literal|"%s"
argument_list|,
name|__FUNCTION__
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|releaseQt
name|void
name|QWindowsOleDataObject
operator|::
name|releaseQt
parameter_list|()
block|{
name|data
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|mimeData
name|QMimeData
modifier|*
name|QWindowsOleDataObject
operator|::
name|mimeData
parameter_list|()
specifier|const
block|{
return|return
name|data
operator|.
name|data
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|reportedPerformedEffect
name|DWORD
name|QWindowsOleDataObject
operator|::
name|reportedPerformedEffect
parameter_list|()
specifier|const
block|{
return|return
name|performedEffect
return|;
block|}
end_function
begin_comment
comment|//---------------------------------------------------------------------
end_comment
begin_comment
comment|//                    IUnknown Methods
end_comment
begin_comment
comment|//---------------------------------------------------------------------
end_comment
begin_function
name|STDMETHODIMP
DECL|function|QueryInterface
name|QWindowsOleDataObject
operator|::
name|QueryInterface
parameter_list|(
name|REFIID
name|iid
parameter_list|,
name|void
name|FAR
modifier|*
name|FAR
modifier|*
name|ppv
parameter_list|)
block|{
if|if
condition|(
name|iid
operator|==
name|IID_IUnknown
operator|||
name|iid
operator|==
name|IID_IDataObject
condition|)
block|{
operator|*
name|ppv
operator|=
name|this
expr_stmt|;
name|AddRef
argument_list|()
expr_stmt|;
return|return
name|NOERROR
return|;
block|}
operator|*
name|ppv
operator|=
name|NULL
expr_stmt|;
return|return
name|ResultFromScode
argument_list|(
name|E_NOINTERFACE
argument_list|)
return|;
block|}
end_function
begin_macro
name|STDMETHODIMP_
argument_list|(
argument|ULONG
argument_list|)
end_macro
begin_macro
DECL|function|AddRef
name|QWindowsOleDataObject
end_macro
begin_expr_stmt
DECL|function|AddRef
operator|::
name|AddRef
operator|(
name|void
operator|)
block|{
return|return
operator|++
name|m_refs
return|;
block|}
end_expr_stmt
begin_macro
name|STDMETHODIMP_
argument_list|(
argument|ULONG
argument_list|)
end_macro
begin_macro
DECL|function|Release
name|QWindowsOleDataObject
end_macro
begin_expr_stmt
DECL|function|Release
operator|::
name|Release
operator|(
name|void
operator|)
block|{
if|if
condition|(
operator|--
name|m_refs
operator|==
literal|0
condition|)
block|{
name|releaseQt
argument_list|()
expr_stmt|;
operator|delete
name|this
expr_stmt|;
return|return
literal|0
return|;
block|}
end_expr_stmt
begin_return
return|return
name|m_refs
return|;
end_return
begin_macro
unit|}  STDMETHODIMP
DECL|function|GetData
name|QWindowsOleDataObject
end_macro
begin_expr_stmt
DECL|function|GetData
operator|::
name|GetData
operator|(
name|LPFORMATETC
name|pformatetc
operator|,
name|LPSTGMEDIUM
name|pmedium
operator|)
block|{
name|HRESULT
name|hr
operator|=
name|ResultFromScode
argument_list|(
name|DATA_E_FORMATETC
argument_list|)
block|;
if|if
condition|(
name|QWindowsContext
operator|::
name|verboseOLE
condition|)
block|{
name|wchar_t
name|buf
index|[
literal|256
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
name|GetClipboardFormatName
argument_list|(
name|pformatetc
operator|->
name|cfFormat
argument_list|,
name|buf
argument_list|,
literal|255
argument_list|)
expr_stmt|;
name|qDebug
argument_list|(
literal|"%s CF = %d : %s"
argument_list|,
name|__FUNCTION__
argument_list|,
name|pformatetc
operator|->
name|cfFormat
argument_list|,
name|qPrintable
argument_list|(
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|buf
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_if
if|if
condition|(
name|data
condition|)
block|{
specifier|const
name|QWindowsMimeConverter
modifier|&
name|mc
init|=
name|QWindowsContext
operator|::
name|instance
argument_list|()
operator|->
name|mimeConverter
argument_list|()
decl_stmt|;
if|if
condition|(
name|QWindowsMime
modifier|*
name|converter
init|=
name|mc
operator|.
name|converterFromMime
argument_list|(
operator|*
name|pformatetc
argument_list|,
name|data
argument_list|)
condition|)
if|if
condition|(
name|converter
operator|->
name|convertFromMime
argument_list|(
operator|*
name|pformatetc
argument_list|,
name|data
argument_list|,
name|pmedium
argument_list|)
condition|)
name|hr
operator|=
name|ResultFromScode
argument_list|(
name|S_OK
argument_list|)
expr_stmt|;
block|}
end_if
begin_if
if|if
condition|(
name|QWindowsContext
operator|::
name|verboseOLE
condition|)
block|{
name|wchar_t
name|buf
index|[
literal|256
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
name|GetClipboardFormatName
argument_list|(
name|pformatetc
operator|->
name|cfFormat
argument_list|,
name|buf
argument_list|,
literal|255
argument_list|)
expr_stmt|;
name|qDebug
argument_list|(
literal|"%s CF = %d : %s returns 0x%x"
argument_list|,
name|__FUNCTION__
argument_list|,
name|pformatetc
operator|->
name|cfFormat
argument_list|,
name|qPrintable
argument_list|(
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|buf
argument_list|)
argument_list|)
argument_list|,
name|int
argument_list|(
name|hr
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_if
begin_return
return|return
name|hr
return|;
end_return
begin_macro
unit|}  STDMETHODIMP
DECL|function|GetDataHere
name|QWindowsOleDataObject
end_macro
begin_expr_stmt
DECL|function|GetDataHere
operator|::
name|GetDataHere
operator|(
name|LPFORMATETC
operator|,
name|LPSTGMEDIUM
operator|)
block|{
return|return
name|ResultFromScode
argument_list|(
name|DATA_E_FORMATETC
argument_list|)
return|;
block|}
end_expr_stmt
begin_function
name|STDMETHODIMP
DECL|function|QueryGetData
name|QWindowsOleDataObject
operator|::
name|QueryGetData
parameter_list|(
name|LPFORMATETC
name|pformatetc
parameter_list|)
block|{
name|HRESULT
name|hr
init|=
name|ResultFromScode
argument_list|(
name|DATA_E_FORMATETC
argument_list|)
decl_stmt|;
if|if
condition|(
name|QWindowsContext
operator|::
name|verboseOLE
operator|>
literal|1
condition|)
name|qDebug
argument_list|(
literal|"%s"
argument_list|,
name|__FUNCTION__
argument_list|)
expr_stmt|;
if|if
condition|(
name|data
condition|)
block|{
specifier|const
name|QWindowsMimeConverter
modifier|&
name|mc
init|=
name|QWindowsContext
operator|::
name|instance
argument_list|()
operator|->
name|mimeConverter
argument_list|()
decl_stmt|;
name|hr
operator|=
name|mc
operator|.
name|converterFromMime
argument_list|(
operator|*
name|pformatetc
argument_list|,
name|data
argument_list|)
condition|?
name|ResultFromScode
argument_list|(
name|S_OK
argument_list|)
else|:
name|ResultFromScode
argument_list|(
name|S_FALSE
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|QWindowsContext
operator|::
name|verboseOLE
operator|>
literal|1
condition|)
name|qDebug
argument_list|(
literal|"%s returns 0x%x"
argument_list|,
name|__FUNCTION__
argument_list|,
name|int
argument_list|(
name|hr
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|hr
return|;
block|}
end_function
begin_function
name|STDMETHODIMP
DECL|function|GetCanonicalFormatEtc
name|QWindowsOleDataObject
operator|::
name|GetCanonicalFormatEtc
parameter_list|(
name|LPFORMATETC
parameter_list|,
name|LPFORMATETC
name|pformatetcOut
parameter_list|)
block|{
name|pformatetcOut
operator|->
name|ptd
operator|=
name|NULL
expr_stmt|;
return|return
name|ResultFromScode
argument_list|(
name|E_NOTIMPL
argument_list|)
return|;
block|}
end_function
begin_function
name|STDMETHODIMP
DECL|function|SetData
name|QWindowsOleDataObject
operator|::
name|SetData
parameter_list|(
name|LPFORMATETC
name|pFormatetc
parameter_list|,
name|STGMEDIUM
modifier|*
name|pMedium
parameter_list|,
name|BOOL
name|fRelease
parameter_list|)
block|{
if|if
condition|(
name|QWindowsContext
operator|::
name|verboseOLE
operator|>
literal|1
condition|)
name|qDebug
argument_list|(
literal|"%s"
argument_list|,
name|__FUNCTION__
argument_list|)
expr_stmt|;
name|HRESULT
name|hr
init|=
name|ResultFromScode
argument_list|(
name|E_NOTIMPL
argument_list|)
decl_stmt|;
if|if
condition|(
name|pFormatetc
operator|->
name|cfFormat
operator|==
name|CF_PERFORMEDDROPEFFECT
operator|&&
name|pMedium
operator|->
name|tymed
operator|==
name|TYMED_HGLOBAL
condition|)
block|{
name|DWORD
modifier|*
name|val
init|=
operator|(
name|DWORD
operator|*
operator|)
name|GlobalLock
argument_list|(
name|pMedium
operator|->
name|hGlobal
argument_list|)
decl_stmt|;
name|performedEffect
operator|=
operator|*
name|val
expr_stmt|;
name|GlobalUnlock
argument_list|(
name|pMedium
operator|->
name|hGlobal
argument_list|)
expr_stmt|;
if|if
condition|(
name|fRelease
condition|)
name|ReleaseStgMedium
argument_list|(
name|pMedium
argument_list|)
expr_stmt|;
name|hr
operator|=
name|ResultFromScode
argument_list|(
name|S_OK
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|QWindowsContext
operator|::
name|verboseOLE
operator|>
literal|1
condition|)
name|qDebug
argument_list|(
literal|"%s returns 0x%x"
argument_list|,
name|__FUNCTION__
argument_list|,
name|int
argument_list|(
name|hr
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|hr
return|;
block|}
end_function
begin_function
name|STDMETHODIMP
DECL|function|EnumFormatEtc
name|QWindowsOleDataObject
operator|::
name|EnumFormatEtc
parameter_list|(
name|DWORD
name|dwDirection
parameter_list|,
name|LPENUMFORMATETC
name|FAR
modifier|*
name|ppenumFormatEtc
parameter_list|)
block|{
if|if
condition|(
name|QWindowsContext
operator|::
name|verboseOLE
operator|>
literal|1
condition|)
name|qDebug
argument_list|(
literal|"%s"
argument_list|,
name|__FUNCTION__
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|data
condition|)
return|return
name|ResultFromScode
argument_list|(
name|DATA_E_FORMATETC
argument_list|)
return|;
name|SCODE
name|sc
init|=
name|S_OK
decl_stmt|;
name|QVector
argument_list|<
name|FORMATETC
argument_list|>
name|fmtetcs
decl_stmt|;
if|if
condition|(
name|dwDirection
operator|==
name|DATADIR_GET
condition|)
block|{
name|QWindowsMimeConverter
modifier|&
name|mc
init|=
name|QWindowsContext
operator|::
name|instance
argument_list|()
operator|->
name|mimeConverter
argument_list|()
decl_stmt|;
name|fmtetcs
operator|=
name|mc
operator|.
name|allFormatsForMime
argument_list|(
name|data
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|FORMATETC
name|formatetc
decl_stmt|;
name|formatetc
operator|.
name|cfFormat
operator|=
name|CF_PERFORMEDDROPEFFECT
expr_stmt|;
name|formatetc
operator|.
name|dwAspect
operator|=
name|DVASPECT_CONTENT
expr_stmt|;
name|formatetc
operator|.
name|lindex
operator|=
operator|-
literal|1
expr_stmt|;
name|formatetc
operator|.
name|ptd
operator|=
name|NULL
expr_stmt|;
name|formatetc
operator|.
name|tymed
operator|=
name|TYMED_HGLOBAL
expr_stmt|;
name|fmtetcs
operator|.
name|append
argument_list|(
name|formatetc
argument_list|)
expr_stmt|;
block|}
name|QWindowsOleEnumFmtEtc
modifier|*
name|enumFmtEtc
init|=
operator|new
name|QWindowsOleEnumFmtEtc
argument_list|(
name|fmtetcs
argument_list|)
decl_stmt|;
operator|*
name|ppenumFormatEtc
operator|=
name|enumFmtEtc
expr_stmt|;
if|if
condition|(
name|enumFmtEtc
operator|->
name|isNull
argument_list|()
condition|)
block|{
operator|delete
name|enumFmtEtc
expr_stmt|;
operator|*
name|ppenumFormatEtc
operator|=
name|NULL
expr_stmt|;
name|sc
operator|=
name|E_OUTOFMEMORY
expr_stmt|;
block|}
return|return
name|ResultFromScode
argument_list|(
name|sc
argument_list|)
return|;
block|}
end_function
begin_function
name|STDMETHODIMP
DECL|function|DAdvise
name|QWindowsOleDataObject
operator|::
name|DAdvise
parameter_list|(
name|FORMATETC
name|FAR
modifier|*
parameter_list|,
name|DWORD
parameter_list|,
name|LPADVISESINK
parameter_list|,
name|DWORD
name|FAR
modifier|*
parameter_list|)
block|{
return|return
name|ResultFromScode
argument_list|(
name|OLE_E_ADVISENOTSUPPORTED
argument_list|)
return|;
block|}
end_function
begin_function
name|STDMETHODIMP
DECL|function|DUnadvise
name|QWindowsOleDataObject
operator|::
name|DUnadvise
parameter_list|(
name|DWORD
parameter_list|)
block|{
return|return
name|ResultFromScode
argument_list|(
name|OLE_E_ADVISENOTSUPPORTED
argument_list|)
return|;
block|}
end_function
begin_function
name|STDMETHODIMP
DECL|function|EnumDAdvise
name|QWindowsOleDataObject
operator|::
name|EnumDAdvise
parameter_list|(
name|LPENUMSTATDATA
name|FAR
modifier|*
parameter_list|)
block|{
return|return
name|ResultFromScode
argument_list|(
name|OLE_E_ADVISENOTSUPPORTED
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \class QWindowsOleEnumFmtEtc     \brief Enumerates the FORMATETC structures supported by QWindowsOleDataObject.     \ingroup qt-lighthouse-win */
end_comment
begin_constructor
DECL|function|QWindowsOleEnumFmtEtc
name|QWindowsOleEnumFmtEtc
operator|::
name|QWindowsOleEnumFmtEtc
parameter_list|(
specifier|const
name|QVector
argument_list|<
name|FORMATETC
argument_list|>
modifier|&
name|fmtetcs
parameter_list|)
member_init_list|:
name|m_dwRefs
argument_list|(
literal|1
argument_list|)
member_init_list|,
name|m_nIndex
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_isNull
argument_list|(
literal|false
argument_list|)
block|{
if|if
condition|(
name|QWindowsContext
operator|::
name|verboseOLE
operator|>
literal|1
condition|)
name|qDebug
argument_list|(
literal|"%s"
argument_list|,
name|__FUNCTION__
argument_list|)
expr_stmt|;
name|m_lpfmtetcs
operator|.
name|reserve
argument_list|(
name|fmtetcs
operator|.
name|count
argument_list|()
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|idx
init|=
literal|0
init|;
name|idx
operator|<
name|fmtetcs
operator|.
name|count
argument_list|()
condition|;
operator|++
name|idx
control|)
block|{
name|LPFORMATETC
name|destetc
init|=
operator|new
name|FORMATETC
argument_list|()
decl_stmt|;
if|if
condition|(
name|copyFormatEtc
argument_list|(
name|destetc
argument_list|,
operator|(
name|LPFORMATETC
operator|)
operator|&
operator|(
name|fmtetcs
operator|.
name|at
argument_list|(
name|idx
argument_list|)
operator|)
argument_list|)
condition|)
block|{
name|m_lpfmtetcs
operator|.
name|append
argument_list|(
name|destetc
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|m_isNull
operator|=
literal|true
expr_stmt|;
operator|delete
name|destetc
expr_stmt|;
break|break;
block|}
block|}
block|}
end_constructor
begin_constructor
DECL|function|QWindowsOleEnumFmtEtc
name|QWindowsOleEnumFmtEtc
operator|::
name|QWindowsOleEnumFmtEtc
parameter_list|(
specifier|const
name|QVector
argument_list|<
name|LPFORMATETC
argument_list|>
modifier|&
name|lpfmtetcs
parameter_list|)
member_init_list|:
name|m_dwRefs
argument_list|(
literal|1
argument_list|)
member_init_list|,
name|m_nIndex
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_isNull
argument_list|(
literal|false
argument_list|)
block|{
if|if
condition|(
name|QWindowsContext
operator|::
name|verboseOLE
operator|>
literal|1
condition|)
name|qDebug
argument_list|(
literal|"%s"
argument_list|,
name|__FUNCTION__
argument_list|)
expr_stmt|;
name|m_lpfmtetcs
operator|.
name|reserve
argument_list|(
name|lpfmtetcs
operator|.
name|count
argument_list|()
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|idx
init|=
literal|0
init|;
name|idx
operator|<
name|lpfmtetcs
operator|.
name|count
argument_list|()
condition|;
operator|++
name|idx
control|)
block|{
name|LPFORMATETC
name|srcetc
init|=
name|lpfmtetcs
operator|.
name|at
argument_list|(
name|idx
argument_list|)
decl_stmt|;
name|LPFORMATETC
name|destetc
init|=
operator|new
name|FORMATETC
argument_list|()
decl_stmt|;
if|if
condition|(
name|copyFormatEtc
argument_list|(
name|destetc
argument_list|,
name|srcetc
argument_list|)
condition|)
block|{
name|m_lpfmtetcs
operator|.
name|append
argument_list|(
name|destetc
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|m_isNull
operator|=
literal|true
expr_stmt|;
operator|delete
name|destetc
expr_stmt|;
break|break;
block|}
block|}
block|}
end_constructor
begin_destructor
DECL|function|~QWindowsOleEnumFmtEtc
name|QWindowsOleEnumFmtEtc
operator|::
name|~
name|QWindowsOleEnumFmtEtc
parameter_list|()
block|{
name|LPMALLOC
name|pmalloc
decl_stmt|;
if|if
condition|(
name|CoGetMalloc
argument_list|(
name|MEMCTX_TASK
argument_list|,
operator|&
name|pmalloc
argument_list|)
operator|==
name|NOERROR
condition|)
block|{
for|for
control|(
name|int
name|idx
init|=
literal|0
init|;
name|idx
operator|<
name|m_lpfmtetcs
operator|.
name|count
argument_list|()
condition|;
operator|++
name|idx
control|)
block|{
name|LPFORMATETC
name|tmpetc
init|=
name|m_lpfmtetcs
operator|.
name|at
argument_list|(
name|idx
argument_list|)
decl_stmt|;
if|if
condition|(
name|tmpetc
operator|->
name|ptd
condition|)
name|pmalloc
operator|->
name|Free
argument_list|(
name|tmpetc
operator|->
name|ptd
argument_list|)
expr_stmt|;
operator|delete
name|tmpetc
expr_stmt|;
block|}
name|pmalloc
operator|->
name|Release
argument_list|()
expr_stmt|;
block|}
name|m_lpfmtetcs
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|isNull
name|bool
name|QWindowsOleEnumFmtEtc
operator|::
name|isNull
parameter_list|()
specifier|const
block|{
return|return
name|m_isNull
return|;
block|}
end_function
begin_comment
comment|// IUnknown methods
end_comment
begin_function
name|STDMETHODIMP
DECL|function|QueryInterface
name|QWindowsOleEnumFmtEtc
operator|::
name|QueryInterface
parameter_list|(
name|REFIID
name|riid
parameter_list|,
name|void
name|FAR
modifier|*
name|FAR
modifier|*
name|ppvObj
parameter_list|)
block|{
if|if
condition|(
name|riid
operator|==
name|IID_IUnknown
operator|||
name|riid
operator|==
name|IID_IEnumFORMATETC
condition|)
block|{
operator|*
name|ppvObj
operator|=
name|this
expr_stmt|;
name|AddRef
argument_list|()
expr_stmt|;
return|return
name|NOERROR
return|;
block|}
operator|*
name|ppvObj
operator|=
name|NULL
expr_stmt|;
return|return
name|ResultFromScode
argument_list|(
name|E_NOINTERFACE
argument_list|)
return|;
block|}
end_function
begin_macro
name|STDMETHODIMP_
argument_list|(
argument|ULONG
argument_list|)
end_macro
begin_macro
DECL|function|AddRef
name|QWindowsOleEnumFmtEtc
end_macro
begin_expr_stmt
DECL|function|AddRef
operator|::
name|AddRef
operator|(
name|void
operator|)
block|{
return|return
operator|++
name|m_dwRefs
return|;
block|}
end_expr_stmt
begin_macro
name|STDMETHODIMP_
argument_list|(
argument|ULONG
argument_list|)
end_macro
begin_macro
DECL|function|Release
name|QWindowsOleEnumFmtEtc
end_macro
begin_expr_stmt
DECL|function|Release
operator|::
name|Release
operator|(
name|void
operator|)
block|{
if|if
condition|(
operator|--
name|m_dwRefs
operator|==
literal|0
condition|)
block|{
operator|delete
name|this
expr_stmt|;
return|return
literal|0
return|;
block|}
end_expr_stmt
begin_return
return|return
name|m_dwRefs
return|;
end_return
begin_comment
unit|}
comment|// IEnumFORMATETC methods
end_comment
begin_macro
unit|STDMETHODIMP
DECL|function|Next
name|QWindowsOleEnumFmtEtc
end_macro
begin_expr_stmt
DECL|function|Next
operator|::
name|Next
operator|(
name|ULONG
name|celt
operator|,
name|LPFORMATETC
name|rgelt
operator|,
name|ULONG
name|FAR
operator|*
name|pceltFetched
operator|)
block|{
name|ULONG
name|i
operator|=
literal|0
block|;
name|ULONG
name|nOffset
block|;
if|if
condition|(
name|rgelt
operator|==
name|NULL
condition|)
return|return
name|ResultFromScode
argument_list|(
name|E_INVALIDARG
argument_list|)
return|;
end_expr_stmt
begin_while
while|while
condition|(
name|i
operator|<
name|celt
condition|)
block|{
name|nOffset
operator|=
name|m_nIndex
operator|+
name|i
expr_stmt|;
if|if
condition|(
name|nOffset
operator|<
name|ULONG
argument_list|(
name|m_lpfmtetcs
operator|.
name|count
argument_list|()
argument_list|)
condition|)
block|{
name|copyFormatEtc
argument_list|(
operator|(
name|LPFORMATETC
operator|)
operator|&
operator|(
name|rgelt
index|[
name|i
index|]
operator|)
argument_list|,
name|m_lpfmtetcs
operator|.
name|at
argument_list|(
name|nOffset
argument_list|)
argument_list|)
expr_stmt|;
name|i
operator|++
expr_stmt|;
block|}
else|else
block|{
break|break;
block|}
block|}
end_while
begin_expr_stmt
name|m_nIndex
operator|+=
operator|(
name|WORD
operator|)
name|i
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
name|pceltFetched
operator|!=
name|NULL
condition|)
operator|*
name|pceltFetched
operator|=
name|i
expr_stmt|;
end_if
begin_if
if|if
condition|(
name|i
operator|!=
name|celt
condition|)
return|return
name|ResultFromScode
argument_list|(
name|S_FALSE
argument_list|)
return|;
end_if
begin_return
return|return
name|NOERROR
return|;
end_return
begin_macro
unit|}  STDMETHODIMP
DECL|function|Skip
name|QWindowsOleEnumFmtEtc
end_macro
begin_expr_stmt
DECL|function|Skip
operator|::
name|Skip
operator|(
name|ULONG
name|celt
operator|)
block|{
name|ULONG
name|i
operator|=
literal|0
block|;
name|ULONG
name|nOffset
block|;
while|while
condition|(
name|i
operator|<
name|celt
condition|)
block|{
name|nOffset
operator|=
name|m_nIndex
operator|+
name|i
expr_stmt|;
if|if
condition|(
name|nOffset
operator|<
name|ULONG
argument_list|(
name|m_lpfmtetcs
operator|.
name|count
argument_list|()
argument_list|)
condition|)
block|{
name|i
operator|++
expr_stmt|;
block|}
end_expr_stmt
begin_else
else|else
block|{
break|break;
block|}
end_else
begin_expr_stmt
unit|}      m_nIndex
operator|+=
operator|(
name|WORD
operator|)
name|i
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
name|i
operator|!=
name|celt
condition|)
return|return
name|ResultFromScode
argument_list|(
name|S_FALSE
argument_list|)
return|;
end_if
begin_return
return|return
name|NOERROR
return|;
end_return
begin_macro
unit|}  STDMETHODIMP
DECL|function|Reset
name|QWindowsOleEnumFmtEtc
end_macro
begin_expr_stmt
DECL|function|Reset
operator|::
name|Reset
operator|(
operator|)
block|{
name|m_nIndex
operator|=
literal|0
block|;
return|return
name|NOERROR
return|;
block|}
end_expr_stmt
begin_function
name|STDMETHODIMP
DECL|function|Clone
name|QWindowsOleEnumFmtEtc
operator|::
name|Clone
parameter_list|(
name|LPENUMFORMATETC
name|FAR
modifier|*
name|newEnum
parameter_list|)
block|{
if|if
condition|(
name|newEnum
operator|==
name|NULL
condition|)
return|return
name|ResultFromScode
argument_list|(
name|E_INVALIDARG
argument_list|)
return|;
name|QWindowsOleEnumFmtEtc
modifier|*
name|result
init|=
operator|new
name|QWindowsOleEnumFmtEtc
argument_list|(
name|m_lpfmtetcs
argument_list|)
decl_stmt|;
name|result
operator|->
name|m_nIndex
operator|=
name|m_nIndex
expr_stmt|;
if|if
condition|(
name|result
operator|->
name|isNull
argument_list|()
condition|)
block|{
operator|delete
name|result
expr_stmt|;
return|return
name|ResultFromScode
argument_list|(
name|E_OUTOFMEMORY
argument_list|)
return|;
block|}
else|else
block|{
operator|*
name|newEnum
operator|=
name|result
expr_stmt|;
block|}
return|return
name|NOERROR
return|;
block|}
end_function
begin_function
DECL|function|copyFormatEtc
name|bool
name|QWindowsOleEnumFmtEtc
operator|::
name|copyFormatEtc
parameter_list|(
name|LPFORMATETC
name|dest
parameter_list|,
name|LPFORMATETC
name|src
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|dest
operator|==
name|NULL
operator|||
name|src
operator|==
name|NULL
condition|)
return|return
literal|false
return|;
operator|*
name|dest
operator|=
operator|*
name|src
expr_stmt|;
if|if
condition|(
name|src
operator|->
name|ptd
condition|)
block|{
name|LPMALLOC
name|pmalloc
decl_stmt|;
if|if
condition|(
name|CoGetMalloc
argument_list|(
name|MEMCTX_TASK
argument_list|,
operator|&
name|pmalloc
argument_list|)
operator|!=
name|NOERROR
condition|)
return|return
literal|false
return|;
name|pmalloc
operator|->
name|Alloc
argument_list|(
name|src
operator|->
name|ptd
operator|->
name|tdSize
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
name|dest
operator|->
name|ptd
argument_list|,
name|src
operator|->
name|ptd
argument_list|,
name|size_t
argument_list|(
name|src
operator|->
name|ptd
operator|->
name|tdSize
argument_list|)
argument_list|)
expr_stmt|;
name|pmalloc
operator|->
name|Release
argument_list|()
expr_stmt|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
