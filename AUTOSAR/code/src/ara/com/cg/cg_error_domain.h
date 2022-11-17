#ifndef CG_ERROR_DOMAIN_H
#define CG_ERROR_DOMAIN_H

// [SWS_CM_99023]{DRAFT} Definition general ara::com::cg errors
namespace ara{
    namespace com{
        namespace cg{
            enum class CgErrc : ara::core::ErrorDomain::CodeType {
                kCommunicationGroupNotActive = 1,   //Commincation Group not active/connected by a Server.
                kNoClients = 2,                     //No communication group clients.
                kWrongClientAddress = 3,            //Wrong client address
                kBindingError = 4,                  //Error at technology binding
                kMemoryError = 5,                   //Memory Error.
                kServerExists = 6                   //Other server already connected to communication group.
            };
            
        } // namespace cg
    } // namespace com
} // namespace ara

#endif