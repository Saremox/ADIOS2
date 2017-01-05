/*
 * CFStream.h
 *
 *  Created on: Oct 18, 2016
 *      Author: wfg
 */

#ifndef FSTREAM_H_
#define FSTREAM_H_


#include <fstream>

#include "core/Transport.h"


namespace adios
{

/**
 * Class that defines a transport method using C++ file streams
 */
class FStream : public Transport
{

public:

    FStream( MPI_Comm mpiComm, const bool debugMode, const std::vector<std::string>& arguments );

    ~FStream( );

    void Open( const std::string name, const std::string accessMode );

    void SetBuffer( char* buffer, std::size_t size );

    void Write( const char* buffer, std::size_t size );

    void Flush( );

    void Close( );

private:

    std::fstream m_Data; ///< file stream under name.bp.dir/name.bp.rank

    bool m_HasMetadataFile = false; ///< true if metadata file is defined in arguments as have_metadata_file=1
    std::fstream m_Metadata; ///< file stream under name.bp storing metadata

    void Init( const std::vector<std::string>& arguments );

};


} //end namespace



#endif /* FSTREAM_H_ */
