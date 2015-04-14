begin_unit
begin_comment
comment|// Copyright 2012 the V8 project authors. All rights reserved.
end_comment
begin_comment
comment|// Redistribution and use in source and binary forms, with or without
end_comment
begin_comment
comment|// modification, are permitted provided that the following conditions are
end_comment
begin_comment
comment|// met:
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|//     * Redistributions of source code must retain the above copyright
end_comment
begin_comment
comment|//       notice, this list of conditions and the following disclaimer.
end_comment
begin_comment
comment|//     * Redistributions in binary form must reproduce the above
end_comment
begin_comment
comment|//       copyright notice, this list of conditions and the following
end_comment
begin_comment
comment|//       disclaimer in the documentation and/or other materials provided
end_comment
begin_comment
comment|//       with the distribution.
end_comment
begin_comment
comment|//     * Neither the name of Google Inc. nor the names of its
end_comment
begin_comment
comment|//       contributors may be used to endorse or promote products derived
end_comment
begin_comment
comment|//       from this software without specific prior written permission.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
end_comment
begin_comment
comment|// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
end_comment
begin_comment
comment|// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
end_comment
begin_comment
comment|// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
end_comment
begin_comment
comment|// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
end_comment
begin_comment
comment|// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
end_comment
begin_comment
comment|// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
end_comment
begin_comment
comment|// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
end_comment
begin_comment
comment|// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
end_comment
begin_comment
comment|// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
end_comment
begin_comment
comment|// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|DOUBLE_CONVERSION_DOUBLE_H_
end_ifndef
begin_define
DECL|macro|DOUBLE_CONVERSION_DOUBLE_H_
define|#
directive|define
name|DOUBLE_CONVERSION_DOUBLE_H_
end_define
begin_include
include|#
directive|include
file|"diy-fp.h"
end_include
begin_decl_stmt
name|namespace
name|double_conversion
block|{
comment|// We assume that doubles and uint64_t have the same endianness.
specifier|static
name|uint64_t
name|double_to_uint64
parameter_list|(
name|double
name|d
parameter_list|)
block|{
return|return
name|BitCast
operator|<
name|uint64_t
operator|>
operator|(
name|d
operator|)
return|;
block|}
specifier|static
name|double
name|uint64_to_double
parameter_list|(
name|uint64_t
name|d64
parameter_list|)
block|{
return|return
name|BitCast
operator|<
name|double
operator|>
operator|(
name|d64
operator|)
return|;
block|}
specifier|static
name|uint32_t
name|float_to_uint32
parameter_list|(
name|float
name|f
parameter_list|)
block|{
return|return
name|BitCast
operator|<
name|uint32_t
operator|>
operator|(
name|f
operator|)
return|;
block|}
specifier|static
name|float
name|uint32_to_float
parameter_list|(
name|uint32_t
name|d32
parameter_list|)
block|{
return|return
name|BitCast
operator|<
name|float
operator|>
operator|(
name|d32
operator|)
return|;
block|}
comment|// Helper functions for doubles.
name|class
name|Double
block|{
name|public
label|:
specifier|static
specifier|const
name|uint64_t
name|kSignMask
init|=
name|UINT64_2PART_C
argument_list|(
literal|0x80000000
argument_list|,
literal|00000000
argument_list|)
decl_stmt|;
specifier|static
specifier|const
name|uint64_t
name|kExponentMask
init|=
name|UINT64_2PART_C
argument_list|(
literal|0x7FF00000
argument_list|,
literal|00000000
argument_list|)
decl_stmt|;
specifier|static
specifier|const
name|uint64_t
name|kSignificandMask
init|=
name|UINT64_2PART_C
argument_list|(
literal|0x000FFFFF
argument_list|,
name|FFFFFFFF
argument_list|)
decl_stmt|;
specifier|static
specifier|const
name|uint64_t
name|kHiddenBit
init|=
name|UINT64_2PART_C
argument_list|(
literal|0x00100000
argument_list|,
literal|00000000
argument_list|)
decl_stmt|;
specifier|static
specifier|const
name|int
name|kPhysicalSignificandSize
init|=
literal|52
decl_stmt|;
comment|// Excludes the hidden bit.
specifier|static
specifier|const
name|int
name|kSignificandSize
init|=
literal|53
decl_stmt|;
name|Double
argument_list|()
operator|:
name|d64_
argument_list|(
literal|0
argument_list|)
block|{}
name|explicit
name|Double
argument_list|(
argument|double d
argument_list|)
operator|:
name|d64_
argument_list|(
argument|double_to_uint64(d)
argument_list|)
block|{}
name|explicit
name|Double
argument_list|(
argument|uint64_t d64
argument_list|)
operator|:
name|d64_
argument_list|(
argument|d64
argument_list|)
block|{}
name|explicit
name|Double
argument_list|(
argument|DiyFp diy_fp
argument_list|)
operator|:
name|d64_
argument_list|(
argument|DiyFpToUint64(diy_fp)
argument_list|)
block|{}
comment|// The value encoded by this Double must be greater or equal to +0.0.
comment|// It must not be special (infinity, or NaN).
name|DiyFp
name|AsDiyFp
argument_list|()
specifier|const
block|{
name|ASSERT
argument_list|(
name|Sign
argument_list|()
operator|>
literal|0
argument_list|)
block|;
name|ASSERT
argument_list|(
operator|!
name|IsSpecial
argument_list|()
argument_list|)
block|;
return|return
name|DiyFp
argument_list|(
name|Significand
argument_list|()
argument_list|,
name|Exponent
argument_list|()
argument_list|)
return|;
block|}
comment|// The value encoded by this Double must be strictly greater than 0.
name|DiyFp
name|AsNormalizedDiyFp
argument_list|()
specifier|const
block|{
name|ASSERT
argument_list|(
name|value
argument_list|()
operator|>
literal|0.0
argument_list|)
block|;
name|uint64_t
name|f
operator|=
name|Significand
argument_list|()
block|;
name|int
name|e
operator|=
name|Exponent
argument_list|()
block|;
comment|// The current double could be a denormal.
while|while
condition|(
operator|(
name|f
operator|&
name|kHiddenBit
operator|)
operator|==
literal|0
condition|)
block|{
name|f
operator|<<=
literal|1
expr_stmt|;
name|e
operator|--
expr_stmt|;
block|}
comment|// Do the final shifts in one go.
name|f
operator|<<=
name|DiyFp
operator|::
name|kSignificandSize
operator|-
name|kSignificandSize
expr_stmt|;
name|e
operator|-=
name|DiyFp
operator|::
name|kSignificandSize
operator|-
name|kSignificandSize
expr_stmt|;
return|return
name|DiyFp
argument_list|(
name|f
argument_list|,
name|e
argument_list|)
return|;
block|}
comment|// Returns the double's bit as uint64.
name|uint64_t
name|AsUint64
argument_list|()
specifier|const
block|{
return|return
name|d64_
return|;
block|}
comment|// Returns the next greater double. Returns +infinity on input +infinity.
name|double
name|NextDouble
argument_list|()
specifier|const
block|{
if|if
condition|(
name|d64_
operator|==
name|kInfinity
condition|)
return|return
name|Double
argument_list|(
name|kInfinity
argument_list|)
operator|.
name|value
argument_list|()
return|;
if|if
condition|(
name|Sign
argument_list|()
operator|<
literal|0
operator|&&
name|Significand
argument_list|()
operator|==
literal|0
condition|)
block|{
comment|// -0.0
return|return
literal|0.0
return|;
block|}
if|if
condition|(
name|Sign
argument_list|()
operator|<
literal|0
condition|)
block|{
return|return
name|Double
argument_list|(
name|d64_
operator|-
literal|1
argument_list|)
operator|.
name|value
argument_list|()
return|;
block|}
else|else
block|{
return|return
name|Double
argument_list|(
name|d64_
operator|+
literal|1
argument_list|)
operator|.
name|value
argument_list|()
return|;
block|}
block|}
end_decl_stmt
begin_expr_stmt
name|double
name|PreviousDouble
argument_list|()
specifier|const
block|{
if|if
condition|(
name|d64_
operator|==
operator|(
name|kInfinity
operator||
name|kSignMask
operator|)
condition|)
return|return
operator|-
name|Double
operator|::
name|Infinity
argument_list|()
return|;
end_expr_stmt
begin_if
if|if
condition|(
name|Sign
argument_list|()
operator|<
literal|0
condition|)
block|{
return|return
name|Double
argument_list|(
name|d64_
operator|+
literal|1
argument_list|)
operator|.
name|value
argument_list|()
return|;
block|}
else|else
block|{
if|if
condition|(
name|Significand
argument_list|()
operator|==
literal|0
condition|)
return|return
operator|-
literal|0.0
return|;
return|return
name|Double
argument_list|(
name|d64_
operator|-
literal|1
argument_list|)
operator|.
name|value
argument_list|()
return|;
block|}
end_if
begin_macro
unit|}    int
name|Exponent
argument_list|()
end_macro
begin_expr_stmt
specifier|const
block|{
if|if
condition|(
name|IsDenormal
argument_list|()
condition|)
return|return
name|kDenormalExponent
return|;
name|uint64_t
name|d64
operator|=
name|AsUint64
argument_list|()
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|int
name|biased_e
init|=
name|static_cast
operator|<
name|int
operator|>
operator|(
operator|(
name|d64
operator|&
name|kExponentMask
operator|)
operator|>>
name|kPhysicalSignificandSize
operator|)
decl_stmt|;
end_decl_stmt
begin_return
return|return
name|biased_e
operator|-
name|kExponentBias
return|;
end_return
begin_macro
unit|}    uint64_t
name|Significand
argument_list|()
end_macro
begin_expr_stmt
specifier|const
block|{
name|uint64_t
name|d64
operator|=
name|AsUint64
argument_list|()
block|;
name|uint64_t
name|significand
operator|=
name|d64
operator|&
name|kSignificandMask
block|;
if|if
condition|(
operator|!
name|IsDenormal
argument_list|()
condition|)
block|{
return|return
name|significand
operator|+
name|kHiddenBit
return|;
block|}
end_expr_stmt
begin_else
else|else
block|{
return|return
name|significand
return|;
block|}
end_else
begin_comment
unit|}
comment|// Returns true if the double is a denormal.
end_comment
begin_macro
unit|bool
name|IsDenormal
argument_list|()
end_macro
begin_expr_stmt
specifier|const
block|{
name|uint64_t
name|d64
operator|=
name|AsUint64
argument_list|()
block|;
return|return
operator|(
name|d64
operator|&
name|kExponentMask
operator|)
operator|==
literal|0
return|;
block|}
end_expr_stmt
begin_comment
comment|// We consider denormals not to be special.
end_comment
begin_comment
comment|// Hence only Infinity and NaN are special.
end_comment
begin_expr_stmt
name|bool
name|IsSpecial
argument_list|()
specifier|const
block|{
name|uint64_t
name|d64
operator|=
name|AsUint64
argument_list|()
block|;
return|return
operator|(
name|d64
operator|&
name|kExponentMask
operator|)
operator|==
name|kExponentMask
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|bool
name|IsNan
argument_list|()
specifier|const
block|{
name|uint64_t
name|d64
operator|=
name|AsUint64
argument_list|()
block|;
return|return
operator|(
operator|(
name|d64
operator|&
name|kExponentMask
operator|)
operator|==
name|kExponentMask
operator|)
operator|&&
operator|(
operator|(
name|d64
operator|&
name|kSignificandMask
operator|)
operator|!=
literal|0
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|bool
name|IsInfinite
argument_list|()
specifier|const
block|{
name|uint64_t
name|d64
operator|=
name|AsUint64
argument_list|()
block|;
return|return
operator|(
operator|(
name|d64
operator|&
name|kExponentMask
operator|)
operator|==
name|kExponentMask
operator|)
operator|&&
operator|(
operator|(
name|d64
operator|&
name|kSignificandMask
operator|)
operator|==
literal|0
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|int
name|Sign
argument_list|()
specifier|const
block|{
name|uint64_t
name|d64
operator|=
name|AsUint64
argument_list|()
block|;
return|return
operator|(
name|d64
operator|&
name|kSignMask
operator|)
operator|==
literal|0
condition|?
literal|1
else|:
operator|-
literal|1
return|;
block|}
end_expr_stmt
begin_comment
comment|// Precondition: the value encoded by this Double must be greater or equal
end_comment
begin_comment
comment|// than +0.0.
end_comment
begin_expr_stmt
name|DiyFp
name|UpperBoundary
argument_list|()
specifier|const
block|{
name|ASSERT
argument_list|(
name|Sign
argument_list|()
operator|>
literal|0
argument_list|)
block|;
return|return
name|DiyFp
argument_list|(
name|Significand
argument_list|()
operator|*
literal|2
operator|+
literal|1
argument_list|,
name|Exponent
argument_list|()
operator|-
literal|1
argument_list|)
return|;
block|}
end_expr_stmt
begin_comment
comment|// Computes the two boundaries of this.
end_comment
begin_comment
comment|// The bigger boundary (m_plus) is normalized. The lower boundary has the same
end_comment
begin_comment
comment|// exponent as m_plus.
end_comment
begin_comment
comment|// Precondition: the value encoded by this Double must be greater than 0.
end_comment
begin_decl_stmt
name|void
name|NormalizedBoundaries
argument_list|(
name|DiyFp
operator|*
name|out_m_minus
argument_list|,
name|DiyFp
operator|*
name|out_m_plus
argument_list|)
decl|const
block|{
name|ASSERT
argument_list|(
name|value
argument_list|()
operator|>
literal|0.0
argument_list|)
expr_stmt|;
name|DiyFp
name|v
init|=
name|this
operator|->
name|AsDiyFp
argument_list|()
decl_stmt|;
name|DiyFp
name|m_plus
init|=
name|DiyFp
operator|::
name|Normalize
argument_list|(
name|DiyFp
argument_list|(
operator|(
name|v
operator|.
name|f
argument_list|()
operator|<<
literal|1
operator|)
operator|+
literal|1
argument_list|,
name|v
operator|.
name|e
argument_list|()
operator|-
literal|1
argument_list|)
argument_list|)
decl_stmt|;
name|DiyFp
name|m_minus
decl_stmt|;
if|if
condition|(
name|LowerBoundaryIsCloser
argument_list|()
condition|)
block|{
name|m_minus
operator|=
name|DiyFp
argument_list|(
operator|(
name|v
operator|.
name|f
argument_list|()
operator|<<
literal|2
operator|)
operator|-
literal|1
argument_list|,
name|v
operator|.
name|e
argument_list|()
operator|-
literal|2
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|m_minus
operator|=
name|DiyFp
argument_list|(
operator|(
name|v
operator|.
name|f
argument_list|()
operator|<<
literal|1
operator|)
operator|-
literal|1
argument_list|,
name|v
operator|.
name|e
argument_list|()
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
name|m_minus
operator|.
name|set_f
argument_list|(
name|m_minus
operator|.
name|f
argument_list|()
operator|<<
operator|(
name|m_minus
operator|.
name|e
argument_list|()
operator|-
name|m_plus
operator|.
name|e
argument_list|()
operator|)
argument_list|)
expr_stmt|;
name|m_minus
operator|.
name|set_e
argument_list|(
name|m_plus
operator|.
name|e
argument_list|()
argument_list|)
expr_stmt|;
operator|*
name|out_m_plus
operator|=
name|m_plus
expr_stmt|;
operator|*
name|out_m_minus
operator|=
name|m_minus
expr_stmt|;
block|}
end_decl_stmt
begin_expr_stmt
name|bool
name|LowerBoundaryIsCloser
argument_list|()
specifier|const
block|{
comment|// The boundary is closer if the significand is of the form f == 2^p-1 then
comment|// the lower boundary is closer.
comment|// Think of v = 1000e10 and v- = 9999e9.
comment|// Then the boundary (== (v - v-)/2) is not just at a distance of 1e9 but
comment|// at a distance of 1e8.
comment|// The only exception is for the smallest normal: the largest denormal is
comment|// at the same distance as its successor.
comment|// Note: denormals have the same exponent as the smallest normals.
name|bool
name|physical_significand_is_zero
operator|=
operator|(
operator|(
name|AsUint64
argument_list|()
operator|&
name|kSignificandMask
operator|)
operator|==
literal|0
operator|)
block|;
return|return
name|physical_significand_is_zero
operator|&&
operator|(
name|Exponent
argument_list|()
operator|!=
name|kDenormalExponent
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|double
name|value
argument_list|()
specifier|const
block|{
return|return
name|uint64_to_double
argument_list|(
name|d64_
argument_list|)
return|;
block|}
end_expr_stmt
begin_comment
comment|// Returns the significand size for a given order of magnitude.
end_comment
begin_comment
comment|// If v = f*2^e with 2^p-1<= f<= 2^p then p+e is v's order of magnitude.
end_comment
begin_comment
comment|// This function returns the number of significant binary digits v will have
end_comment
begin_comment
comment|// once it's encoded into a double. In almost all cases this is equal to
end_comment
begin_comment
comment|// kSignificandSize. The only exceptions are denormals. They start with
end_comment
begin_comment
comment|// leading zeroes and their effective significand-size is hence smaller.
end_comment
begin_function
specifier|static
name|int
name|SignificandSizeForOrderOfMagnitude
parameter_list|(
name|int
name|order
parameter_list|)
block|{
if|if
condition|(
name|order
operator|>=
operator|(
name|kDenormalExponent
operator|+
name|kSignificandSize
operator|)
condition|)
block|{
return|return
name|kSignificandSize
return|;
block|}
if|if
condition|(
name|order
operator|<=
name|kDenormalExponent
condition|)
return|return
literal|0
return|;
return|return
name|order
operator|-
name|kDenormalExponent
return|;
block|}
end_function
begin_function
specifier|static
name|double
name|Infinity
parameter_list|()
block|{
return|return
name|Double
argument_list|(
name|kInfinity
argument_list|)
operator|.
name|value
argument_list|()
return|;
block|}
end_function
begin_function
specifier|static
name|double
name|NaN
parameter_list|()
block|{
return|return
name|Double
argument_list|(
name|kNaN
argument_list|)
operator|.
name|value
argument_list|()
return|;
block|}
end_function
begin_label
name|private
label|:
end_label
begin_decl_stmt
specifier|static
specifier|const
name|int
name|kExponentBias
init|=
literal|0x3FF
operator|+
name|kPhysicalSignificandSize
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|static
specifier|const
name|int
name|kDenormalExponent
init|=
operator|-
name|kExponentBias
operator|+
literal|1
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|static
specifier|const
name|int
name|kMaxExponent
init|=
literal|0x7FF
operator|-
name|kExponentBias
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|static
specifier|const
name|uint64_t
name|kInfinity
init|=
name|UINT64_2PART_C
argument_list|(
literal|0x7FF00000
argument_list|,
literal|00000000
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|static
specifier|const
name|uint64_t
name|kNaN
init|=
name|UINT64_2PART_C
argument_list|(
literal|0x7FF80000
argument_list|,
literal|00000000
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|const
name|uint64_t
name|d64_
decl_stmt|;
end_decl_stmt
begin_function
specifier|static
name|uint64_t
name|DiyFpToUint64
parameter_list|(
name|DiyFp
name|diy_fp
parameter_list|)
block|{
name|uint64_t
name|significand
init|=
name|diy_fp
operator|.
name|f
argument_list|()
decl_stmt|;
name|int
name|exponent
init|=
name|diy_fp
operator|.
name|e
argument_list|()
decl_stmt|;
while|while
condition|(
name|significand
operator|>
name|kHiddenBit
operator|+
name|kSignificandMask
condition|)
block|{
name|significand
operator|>>=
literal|1
expr_stmt|;
name|exponent
operator|++
expr_stmt|;
block|}
if|if
condition|(
name|exponent
operator|>=
name|kMaxExponent
condition|)
block|{
return|return
name|kInfinity
return|;
block|}
if|if
condition|(
name|exponent
operator|<
name|kDenormalExponent
condition|)
block|{
return|return
literal|0
return|;
block|}
while|while
condition|(
name|exponent
operator|>
name|kDenormalExponent
operator|&&
operator|(
name|significand
operator|&
name|kHiddenBit
operator|)
operator|==
literal|0
condition|)
block|{
name|significand
operator|<<=
literal|1
expr_stmt|;
name|exponent
operator|--
expr_stmt|;
block|}
name|uint64_t
name|biased_exponent
decl_stmt|;
if|if
condition|(
name|exponent
operator|==
name|kDenormalExponent
operator|&&
operator|(
name|significand
operator|&
name|kHiddenBit
operator|)
operator|==
literal|0
condition|)
block|{
name|biased_exponent
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
name|biased_exponent
operator|=
name|static_cast
operator|<
name|uint64_t
operator|>
operator|(
name|exponent
operator|+
name|kExponentBias
operator|)
expr_stmt|;
block|}
return|return
operator|(
name|significand
operator|&
name|kSignificandMask
operator|)
operator||
operator|(
name|biased_exponent
operator|<<
name|kPhysicalSignificandSize
operator|)
return|;
block|}
end_function
begin_expr_stmt
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|Double
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
unit|};
name|class
name|Single
block|{
name|public
label|:
specifier|static
specifier|const
name|uint32_t
name|kSignMask
init|=
literal|0x80000000
decl_stmt|;
specifier|static
specifier|const
name|uint32_t
name|kExponentMask
init|=
literal|0x7F800000
decl_stmt|;
specifier|static
specifier|const
name|uint32_t
name|kSignificandMask
init|=
literal|0x007FFFFF
decl_stmt|;
specifier|static
specifier|const
name|uint32_t
name|kHiddenBit
init|=
literal|0x00800000
decl_stmt|;
specifier|static
specifier|const
name|int
name|kPhysicalSignificandSize
init|=
literal|23
decl_stmt|;
comment|// Excludes the hidden bit.
specifier|static
specifier|const
name|int
name|kSignificandSize
init|=
literal|24
decl_stmt|;
name|Single
argument_list|()
operator|:
name|d32_
argument_list|(
literal|0
argument_list|)
block|{}
name|explicit
name|Single
argument_list|(
argument|float f
argument_list|)
operator|:
name|d32_
argument_list|(
argument|float_to_uint32(f)
argument_list|)
block|{}
name|explicit
name|Single
argument_list|(
argument|uint32_t d32
argument_list|)
operator|:
name|d32_
argument_list|(
argument|d32
argument_list|)
block|{}
comment|// The value encoded by this Single must be greater or equal to +0.0.
comment|// It must not be special (infinity, or NaN).
name|DiyFp
name|AsDiyFp
argument_list|()
specifier|const
block|{
name|ASSERT
argument_list|(
name|Sign
argument_list|()
operator|>
literal|0
argument_list|)
block|;
name|ASSERT
argument_list|(
operator|!
name|IsSpecial
argument_list|()
argument_list|)
block|;
return|return
name|DiyFp
argument_list|(
name|Significand
argument_list|()
argument_list|,
name|Exponent
argument_list|()
argument_list|)
return|;
block|}
comment|// Returns the single's bit as uint64.
name|uint32_t
name|AsUint32
argument_list|()
specifier|const
block|{
return|return
name|d32_
return|;
block|}
name|int
name|Exponent
argument_list|()
specifier|const
block|{
if|if
condition|(
name|IsDenormal
argument_list|()
condition|)
return|return
name|kDenormalExponent
return|;
name|uint32_t
name|d32
operator|=
name|AsUint32
argument_list|()
expr_stmt|;
name|int
name|biased_e
init|=
name|static_cast
operator|<
name|int
operator|>
operator|(
operator|(
name|d32
operator|&
name|kExponentMask
operator|)
operator|>>
name|kPhysicalSignificandSize
operator|)
decl_stmt|;
return|return
name|biased_e
operator|-
name|kExponentBias
return|;
block|}
end_decl_stmt
begin_expr_stmt
name|uint32_t
name|Significand
argument_list|()
specifier|const
block|{
name|uint32_t
name|d32
operator|=
name|AsUint32
argument_list|()
block|;
name|uint32_t
name|significand
operator|=
name|d32
operator|&
name|kSignificandMask
block|;
if|if
condition|(
operator|!
name|IsDenormal
argument_list|()
condition|)
block|{
return|return
name|significand
operator|+
name|kHiddenBit
return|;
block|}
end_expr_stmt
begin_else
else|else
block|{
return|return
name|significand
return|;
block|}
end_else
begin_comment
unit|}
comment|// Returns true if the single is a denormal.
end_comment
begin_macro
unit|bool
name|IsDenormal
argument_list|()
end_macro
begin_expr_stmt
specifier|const
block|{
name|uint32_t
name|d32
operator|=
name|AsUint32
argument_list|()
block|;
return|return
operator|(
name|d32
operator|&
name|kExponentMask
operator|)
operator|==
literal|0
return|;
block|}
end_expr_stmt
begin_comment
comment|// We consider denormals not to be special.
end_comment
begin_comment
comment|// Hence only Infinity and NaN are special.
end_comment
begin_expr_stmt
name|bool
name|IsSpecial
argument_list|()
specifier|const
block|{
name|uint32_t
name|d32
operator|=
name|AsUint32
argument_list|()
block|;
return|return
operator|(
name|d32
operator|&
name|kExponentMask
operator|)
operator|==
name|kExponentMask
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|bool
name|IsNan
argument_list|()
specifier|const
block|{
name|uint32_t
name|d32
operator|=
name|AsUint32
argument_list|()
block|;
return|return
operator|(
operator|(
name|d32
operator|&
name|kExponentMask
operator|)
operator|==
name|kExponentMask
operator|)
operator|&&
operator|(
operator|(
name|d32
operator|&
name|kSignificandMask
operator|)
operator|!=
literal|0
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|bool
name|IsInfinite
argument_list|()
specifier|const
block|{
name|uint32_t
name|d32
operator|=
name|AsUint32
argument_list|()
block|;
return|return
operator|(
operator|(
name|d32
operator|&
name|kExponentMask
operator|)
operator|==
name|kExponentMask
operator|)
operator|&&
operator|(
operator|(
name|d32
operator|&
name|kSignificandMask
operator|)
operator|==
literal|0
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|int
name|Sign
argument_list|()
specifier|const
block|{
name|uint32_t
name|d32
operator|=
name|AsUint32
argument_list|()
block|;
return|return
operator|(
name|d32
operator|&
name|kSignMask
operator|)
operator|==
literal|0
condition|?
literal|1
else|:
operator|-
literal|1
return|;
block|}
end_expr_stmt
begin_comment
comment|// Computes the two boundaries of this.
end_comment
begin_comment
comment|// The bigger boundary (m_plus) is normalized. The lower boundary has the same
end_comment
begin_comment
comment|// exponent as m_plus.
end_comment
begin_comment
comment|// Precondition: the value encoded by this Single must be greater than 0.
end_comment
begin_decl_stmt
name|void
name|NormalizedBoundaries
argument_list|(
name|DiyFp
operator|*
name|out_m_minus
argument_list|,
name|DiyFp
operator|*
name|out_m_plus
argument_list|)
decl|const
block|{
name|ASSERT
argument_list|(
name|value
argument_list|()
operator|>
literal|0.0
argument_list|)
expr_stmt|;
name|DiyFp
name|v
init|=
name|this
operator|->
name|AsDiyFp
argument_list|()
decl_stmt|;
name|DiyFp
name|m_plus
init|=
name|DiyFp
operator|::
name|Normalize
argument_list|(
name|DiyFp
argument_list|(
operator|(
name|v
operator|.
name|f
argument_list|()
operator|<<
literal|1
operator|)
operator|+
literal|1
argument_list|,
name|v
operator|.
name|e
argument_list|()
operator|-
literal|1
argument_list|)
argument_list|)
decl_stmt|;
name|DiyFp
name|m_minus
decl_stmt|;
if|if
condition|(
name|LowerBoundaryIsCloser
argument_list|()
condition|)
block|{
name|m_minus
operator|=
name|DiyFp
argument_list|(
operator|(
name|v
operator|.
name|f
argument_list|()
operator|<<
literal|2
operator|)
operator|-
literal|1
argument_list|,
name|v
operator|.
name|e
argument_list|()
operator|-
literal|2
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|m_minus
operator|=
name|DiyFp
argument_list|(
operator|(
name|v
operator|.
name|f
argument_list|()
operator|<<
literal|1
operator|)
operator|-
literal|1
argument_list|,
name|v
operator|.
name|e
argument_list|()
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
name|m_minus
operator|.
name|set_f
argument_list|(
name|m_minus
operator|.
name|f
argument_list|()
operator|<<
operator|(
name|m_minus
operator|.
name|e
argument_list|()
operator|-
name|m_plus
operator|.
name|e
argument_list|()
operator|)
argument_list|)
expr_stmt|;
name|m_minus
operator|.
name|set_e
argument_list|(
name|m_plus
operator|.
name|e
argument_list|()
argument_list|)
expr_stmt|;
operator|*
name|out_m_plus
operator|=
name|m_plus
expr_stmt|;
operator|*
name|out_m_minus
operator|=
name|m_minus
expr_stmt|;
block|}
end_decl_stmt
begin_comment
comment|// Precondition: the value encoded by this Single must be greater or equal
end_comment
begin_comment
comment|// than +0.0.
end_comment
begin_expr_stmt
name|DiyFp
name|UpperBoundary
argument_list|()
specifier|const
block|{
name|ASSERT
argument_list|(
name|Sign
argument_list|()
operator|>
literal|0
argument_list|)
block|;
return|return
name|DiyFp
argument_list|(
name|Significand
argument_list|()
operator|*
literal|2
operator|+
literal|1
argument_list|,
name|Exponent
argument_list|()
operator|-
literal|1
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|bool
name|LowerBoundaryIsCloser
argument_list|()
specifier|const
block|{
comment|// The boundary is closer if the significand is of the form f == 2^p-1 then
comment|// the lower boundary is closer.
comment|// Think of v = 1000e10 and v- = 9999e9.
comment|// Then the boundary (== (v - v-)/2) is not just at a distance of 1e9 but
comment|// at a distance of 1e8.
comment|// The only exception is for the smallest normal: the largest denormal is
comment|// at the same distance as its successor.
comment|// Note: denormals have the same exponent as the smallest normals.
name|bool
name|physical_significand_is_zero
operator|=
operator|(
operator|(
name|AsUint32
argument_list|()
operator|&
name|kSignificandMask
operator|)
operator|==
literal|0
operator|)
block|;
return|return
name|physical_significand_is_zero
operator|&&
operator|(
name|Exponent
argument_list|()
operator|!=
name|kDenormalExponent
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|float
name|value
argument_list|()
specifier|const
block|{
return|return
name|uint32_to_float
argument_list|(
name|d32_
argument_list|)
return|;
block|}
end_expr_stmt
begin_function
specifier|static
name|float
name|Infinity
parameter_list|()
block|{
return|return
name|Single
argument_list|(
name|kInfinity
argument_list|)
operator|.
name|value
argument_list|()
return|;
block|}
end_function
begin_function
specifier|static
name|float
name|NaN
parameter_list|()
block|{
return|return
name|Single
argument_list|(
name|kNaN
argument_list|)
operator|.
name|value
argument_list|()
return|;
block|}
end_function
begin_label
name|private
label|:
end_label
begin_decl_stmt
specifier|static
specifier|const
name|int
name|kExponentBias
init|=
literal|0x7F
operator|+
name|kPhysicalSignificandSize
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|static
specifier|const
name|int
name|kDenormalExponent
init|=
operator|-
name|kExponentBias
operator|+
literal|1
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|static
specifier|const
name|int
name|kMaxExponent
init|=
literal|0xFF
operator|-
name|kExponentBias
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|static
specifier|const
name|uint32_t
name|kInfinity
init|=
literal|0x7F800000
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|static
specifier|const
name|uint32_t
name|kNaN
init|=
literal|0x7FC00000
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|const
name|uint32_t
name|d32_
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|Single
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
unit|};  }
comment|// namespace double_conversion
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// DOUBLE_CONVERSION_DOUBLE_H_
end_comment
end_unit