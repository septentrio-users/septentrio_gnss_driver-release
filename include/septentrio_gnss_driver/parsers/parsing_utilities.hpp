// *****************************************************************************
//
// © Copyright 2020, Septentrio NV/SA.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//    1. Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//    2. Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//    3. Neither the name of the copyright holder nor the names of its
//       contributors may be used to endorse or promote products derived
//       from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//
// *****************************************************************************

#ifndef PARSING_UTILITIES_HPP
#define PARSING_UTILITIES_HPP

// C++ library includes
#include <cmath>   // C++ header, corresponds to <math.h> in C
#include <cstdint> // C++ header, corresponds to <stdint.h> in C
#include <ctime>   // C++ header, corresponds to <time.h> in C
#include <string>  // C++ header, corresponds to <string.h> in C
// ROS includes
#include <geometry_msgs/Quaternion.h>
#include <ros/ros.h>

/**
 * @file parsing_utilities.hpp
 * @brief Declares utility functions used when parsing messages
 * @date 17/08/20
 */

namespace parsing_utilities {

    /**
     * @brief Converts an 8-byte-buffer into a double
     * @param[in] buffer A pointer to a buffer containing 8 bytes of data
     * @return The double extracted from the data in the buffer
     */
    double parseDouble(const uint8_t* buffer);

    /**
     * @brief Interprets the contents of "string" as a floating point number of type
     * double
     *
     * It stores the "string"'s value in "value" and returns whether or not all went
     * well.
     * @param[in] string The string whose content should be interpreted as a floating
     * point number
     * @param[out] value The double variable that should be overwritten by the
     * floating point number found in "string"
     * @return True if all went fine, false if not
     */
    bool parseDouble(const std::string& string, double& value);

    /**
     * @brief Converts a 4-byte-buffer into a float
     * @param[in] buffer A pointer to a buffer containing 4 bytes of data
     * @return The float extracted from the data in the buffer
     */
    float parseFloat(const uint8_t* buffer);

    /**
     * @brief Interprets the contents of "string" as a floating point number of type
     * float
     *
     * It stores the "string"'s value in "value" and returns whether or not all went
     * well.
     * @param[in] string The string whose content should be interpreted as a floating
     * point number
     * @param[out] value The float variable that should be overwritten by the
     * floating point number found in "string"
     * @return True if all went fine, false if not
     */
    bool parseFloat(const std::string& string, float& value);

    /**
     * @brief Converts a 2-byte-buffer into a signed 16-bit integer
     * @param[in] buffer A pointer to a buffer containing 2 bytes of data
     * @return The int16_t value extracted from the data in the buffer
     */
    int16_t parseInt16(const uint8_t* buffer);

    /**
     * @brief Interprets the contents of "string" as a integer number of type
     * int16_t.
     *
     * It stores the "string"'s value in "value" and returns whether or not all went
     * well.
     * @param[in] string The string whose content should be interpreted as an integer
     * number
     * @param[out] value The int16_t variable that should be overwritten by the
     * integer number found in "string"
     * @param[in] base The numerical base of the integer in the string, default being
     * 10
     * @return True if all went fine, false if not
     */
    bool parseInt16(const std::string& string, int16_t& value, int32_t base = 10);

    /**
     * @brief Converts a 4-byte-buffer into a signed 32-bit integer
     * @param[in] buffer A pointer to a buffer containing 4 bytes of data
     * @return The int32_t value extracted from the data in the buffer
     */
    int32_t parseInt32(const uint8_t* buffer);

    /**
     * @brief Interprets the contents of "string" as a integer number of type
     * int32_t.
     *
     * It stores the "string"'s value in "value" and returns whether or not all went
     * well.
     * @param[in] string The string whose content should be interpreted as an integer
     * number
     * @param[out] value The int32_t variable that should be overwritten by the
     * integer number found in "string"
     * @param[in] base The numerical base of the integer in the string, default being
     * 10
     * @return True if all went fine, false if not
     */
    bool parseInt32(const std::string& string, int32_t& value, int32_t base = 10);

    /**
     * @brief Interprets the contents of "string" as a unsigned integer number of
     * type uint8_t.
     *
     * It stores the "string"'s value in "value" and returns whether or not all went
     * well.
     * @param[in] string The string whose content should be interpreted as an integer
     * number
     * @param[out] value The uint8_t variable that should be overwritten by the
     * integer number found in "string"
     * @param[in] base The numerical base of the integer in the string, default being
     * 10
     * @return True if all went fine, false if not
     */
    bool parseUInt8(const std::string& string, uint8_t& value, int32_t base = 10);

    /**
     * @brief Converts a 2-byte-buffer into an unsigned 16-bit integer
     * @param[in] buffer A pointer to a buffer containing 2 bytes of data
     * @return The uint16_t value extracted from the data in the buffer
     */
    uint16_t parseUInt16(const uint8_t* buffer);

    /**
     * @brief Interprets the contents of "string" as a unsigned integer number of
     * type uint16_t.
     *
     * It stores the "string"'s value in "value" and returns whether or not all went
     * well.
     * @param[in] string The string whose content should be interpreted as an integer
     * number
     * @param[out] value The uint16_t variable that should be overwritten by the
     * integer number found in "string"
     * @param[in] base The numerical base of the integer in the string, default being
     * 10
     * @return True if all went fine, false if not
     */
    bool parseUInt16(const std::string& string, uint16_t& value, int32_t base = 10);

    /**
     * @brief Converts a 4-byte-buffer into an unsigned 32-bit integer
     * @param[in] buffer A pointer to a buffer containing 4 bytes of data
     * @return The uint32_t value extracted from the data in the buffer
     */
    uint32_t parseUInt32(const uint8_t* buffer);

    /**
     * @brief Interprets the contents of "string" as a unsigned integer number of
     * type uint32_t.
     *
     * It stores the "string"'s value in "value" and returns whether or not all went
     * well.
     * @param[in] string The string whose content should be interpreted as an integer
     * number
     * @param[out] value The uint32_t variable that should be overwritten by the
     * integer number found in "string"
     * @param[in] base The numerical base of the integer in the string, default being
     * 10
     * @return True if all went fine, false if not
     */
    bool parseUInt32(const std::string& string, uint32_t& value, int32_t base = 10);

    /**
     * @brief Converts UTC time from the without-colon-delimiter format to the
     * number-of-seconds-since-midnight format
     * @param[in] utc_double Rrepresents UTC time in the without-colon-delimiter
     * format
     * @return Represents UTC time in the number-of-seconds-since-midnight format
     */
    double convertUTCDoubleToSeconds(double utc_double);

    /**
     * @brief Converts UTC time from the without-colon-delimiter format to Unix Epoch
     * time (a number-of-seconds-since-1970/01/01 format)
     *
     * Note that the type "std::time_t" is usually 32 bits, which also leads to the
     * "Year 2038 Problem".
     * @param[in] utc_double Represents UTC time in the without-colon-delimiter
     * format
     * @return The time_t variable representing Unix Epoch time
     */
    std::time_t convertUTCtoUnix(double utc_double);

    /**
     * @brief Converts latitude or longitude from the DMS notation (in the
     * without-colon-delimiter format), to the pure degree notation
     *
     * Note that DMS stands for "Degrees, Minutes, Seconds".
     * @param[in] dms Represents latitude or longitude in the DMS notation (in the
     * without-colon-delimiter format)
     * @return Represents latitude or longitude in the pure degree notation
     */
    double convertDMSToDegrees(double dms);

    /**
     * @brief Transforms Euler angles to a quaternion
     * @param[in] yaw Yaw, i.e. heading, about the Up-axis
     * @param[in] pitch Pitch about the new North-axis
     * @param[in] roll Roll about the new East-axis
     * @return ROS message representing a quaternion
     */
    geometry_msgs::Quaternion convertEulerToQuaternion(double yaw, double pitch,
                                                       double roll);

    /**
     * @brief Transforms the input polling period [milliseconds] into a uint32_t
     * number that can be appended to either sec or msec for Rx commands
     * @param[in] period_user Polling period in milliseconds as specified by the
     * ROSaic user
     * @return Number to be appended to either sec or msec when sending commands to
     * the Rx
     */
    uint32_t convertUserPeriodToRxCommand(uint32_t period_user);
} // namespace parsing_utilities

#endif // PARSING_UTILITIES_HPP
