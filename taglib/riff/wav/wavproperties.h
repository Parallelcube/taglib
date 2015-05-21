/***************************************************************************
    copyright            : (C) 2008 by Scott Wheeler
    email                : wheeler@kde.org
***************************************************************************/

/***************************************************************************
 *   This library is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU Lesser General Public License version   *
 *   2.1 as published by the Free Software Foundation.                     *
 *                                                                         *
 *   This library is distributed in the hope that it will be useful, but   *
 *   WITHOUT ANY WARRANTY; without even the implied warranty of            *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU     *
 *   Lesser General Public License for more details.                       *
 *                                                                         *
 *   You should have received a copy of the GNU Lesser General Public      *
 *   License along with this library; if not, write to the Free Software   *
 *   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA         *
 *   02110-1301  USA                                                       *
 *                                                                         *
 *   Alternatively, this file is available under the Mozilla Public        *
 *   License Version 1.1.  You may obtain a copy of the License at         *
 *   http://www.mozilla.org/MPL/                                           *
 ***************************************************************************/

#ifndef TAGLIB_WAVPROPERTIES_H
#define TAGLIB_WAVPROPERTIES_H

#include "taglib.h"
#include "audioproperties.h"

namespace TagLib {

  class ByteVector;

  namespace RIFF {

    namespace WAV {

      class File;

      //! An implementation of audio property reading for WAV

      /*!
       * This reads the data from an WAV stream found in the AudioProperties
       * API.
       */

      class TAGLIB_EXPORT Properties : public AudioProperties
      {
      public:
        /*!
         * Create an instance of WAV::Properties with the data read from the
         * ByteVector \a data.
         *
         * \deprecated
         */
        Properties(const ByteVector &data, ReadStyle style);

        /*!
         * Create an instance of WAV::Properties with the data read from the
         * ByteVector \a data and the length calculated using \a streamLength.
         *
         * \deprecated
         */
        Properties(const ByteVector &data, uint streamLength, ReadStyle style);

        /*!
         * Create an instance of WAV::Properties with the data read from the
         * ByteVector \a data and the length calculated using \a streamLength
         * and \a totalSamples.
         *
         * \note totalSamples can be zero if the file doesn't have a 'fact' chunk.
         */
        Properties(const ByteVector &data, uint streamLength, uint totalSamples, ReadStyle style);

        /*!
         * Destroys this WAV::Properties instance.
         */
        virtual ~Properties();

        /*!
         * Returns the length of the file in seconds.  The length is rounded down to
         * the nearest whole second.
         *
         * \note This method is just an alias of lengthInSeconds().
         *
         * \deprecated
         */
        virtual int length() const;

        /*!
         * Returns the length of the file in seconds.  The length is rounded down to
         * the nearest whole second.
         *
         * \see lengthInMilliseconds()
         */
        // BIC: make virtual
        int lengthInSeconds() const;

        /*!
         * Returns the length of the file in milliseconds.
         *
         * \see lengthInSeconds()
         */
        // BIC: make virtual
        int lengthInMilliseconds() const;

        /*!
         * Returns the average bit rate of the file in kb/s.
         */
        virtual int bitrate() const;

        /*!
         * Returns the sample rate in Hz.
         */
        virtual int sampleRate() const;

        /*!
         * Returns the number of audio channels.
         */
        virtual int channels() const;

        /*!
         * Returns the number of bits per audio sample.
         */
        int bitsPerSample() const;

        /*!
         * Returns the number of bits per audio sample.
         *
         * \note This method is just an alias of bitsPerSample().
         *
         * \deprecated
         */
        int sampleWidth() const;

        /*!
         * Returns the number of sample frames.
         */
        uint sampleFrames() const;

        /*!
         * Returns the format ID of the file.
         * 0 for unknown, 1 for PCM, 2 for ADPCM, 3 for 32/64-bit IEEE754, and so forth.
         *
         * \note For further information, refer to \a mmreg.h in Windows Media SDK.
         */
        int format() const;

      private:
        Properties(const Properties &);
        Properties &operator=(const Properties &);

        void read(const ByteVector &data, uint streamLength, uint totalSamples);

        class PropertiesPrivate;
        PropertiesPrivate *d;
      };
    }
  }
}

#endif
