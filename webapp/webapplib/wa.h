/* ========================================================================= *

 *                                                                           *

 *                 The Apache Software License,  Version 1.1                 *

 *                                                                           *

 *         Copyright (c) 1999, 2000  The Apache Software Foundation.         *

 *                           All rights reserved.                            *

 *                                                                           *

 * ========================================================================= *

 *                                                                           *

 * Redistribution and use in source and binary forms,  with or without modi- *

 * fication, are permitted provided that the following conditions are met:   *

 *                                                                           *

 * 1. Redistributions of source code  must retain the above copyright notice *

 *    notice, this list of conditions and the following disclaimer.          *

 *                                                                           *

 * 2. Redistributions  in binary  form  must  reproduce the  above copyright *

 *    notice,  this list of conditions  and the following  disclaimer in the *

 *    documentation and/or other materials provided with the distribution.   *

 *                                                                           *

 * 3. The end-user documentation  included with the redistribution,  if any, *

 *    must include the following acknowlegement:                             *

 *                                                                           *

 *       "This product includes  software developed  by the Apache  Software *

 *        Foundation <http://www.apache.org/>."                              *

 *                                                                           *

 *    Alternately, this acknowlegement may appear in the software itself, if *

 *    and wherever such third-party acknowlegements normally appear.         *

 *                                                                           *

 * 4. The names  "The  Jakarta  Project",  "Tomcat",  and  "Apache  Software *

 *    Foundation"  must not be used  to endorse or promote  products derived *

 *    from this  software without  prior  written  permission.  For  written *

 *    permission, please contact <apache@apache.org>.                        *

 *                                                                           *

 * 5. Products derived from this software may not be called "Apache" nor may *

 *    "Apache" appear in their names without prior written permission of the *

 *    Apache Software Foundation.                                            *

 *                                                                           *

 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESSED OR IMPLIED WARRANTIES *

 * INCLUDING, BUT NOT LIMITED TO,  THE IMPLIED WARRANTIES OF MERCHANTABILITY *

 * AND FITNESS FOR  A PARTICULAR PURPOSE  ARE DISCLAIMED.  IN NO EVENT SHALL *

 * THE APACHE  SOFTWARE  FOUNDATION OR  ITS CONTRIBUTORS  BE LIABLE  FOR ANY *

 * DIRECT,  INDIRECT,   INCIDENTAL,  SPECIAL,  EXEMPLARY,  OR  CONSEQUENTIAL *

 * DAMAGES (INCLUDING,  BUT NOT LIMITED TO,  PROCUREMENT OF SUBSTITUTE GOODS *

 * OR SERVICES;  LOSS OF USE,  DATA,  OR PROFITS;  OR BUSINESS INTERRUPTION) *

 * HOWEVER CAUSED AND  ON ANY  THEORY  OF  LIABILITY,  WHETHER IN  CONTRACT, *

 * STRICT LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN *

 * ANY  WAY  OUT OF  THE  USE OF  THIS  SOFTWARE,  EVEN  IF  ADVISED  OF THE *

 * POSSIBILITY OF SUCH DAMAGE.                                               *

 *                                                                           *

 * ========================================================================= *

 *                                                                           *

 * This software  consists of voluntary  contributions made  by many indivi- *

 * duals on behalf of the  Apache Software Foundation.  For more information *

 * on the Apache Software Foundation, please see <http://www.apache.org/>.   *

 *                                                                           *

 * ========================================================================= */



// CVS $Id$

// Author: Pier Fumagalli <mailto:pier.fumagalli@eng.sun.com>



#ifndef _WA_H_

#define _WA_H_



/* Generic includes */

#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <stdarg.h>

#include <string.h>

#include <netdb.h>

#include <errno.h>

#include <time.h>

#include <sys/errno.h>

#include <sys/types.h>

#include <sys/socket.h>

#include <netinet/in.h>



/* Our name and version */

#ifndef WA_NAME

#define WA_NAME "WebApp"

#endif

#ifndef WA_VERSION

#define WA_VERSION "0.5-dev"

#endif



/* Define TRUE and FALSE */

#ifndef TRUE

#define TRUE 1

#endif



#ifndef FALSE

#define FALSE 0

#endif



/* Define the log mark */

#define WA_LOG __FILE__,__LINE__



/* Types definitions */

typedef int boolean;

typedef struct wa_connection wa_connection;

typedef struct wa_application wa_application;

typedef struct wa_host wa_host;

typedef struct wa_provider wa_provider;

typedef struct wa_header wa_header;

typedef struct wa_request wa_request;

typedef struct wa_callback wa_callback;



/* Other includes from the webapp lib */

#include <wa_host.h>

#include <wa_connection.h>

#include <wa_provider.h>

#include <wa_request.h>

#include <wa_callback.h>



/* Function prototype declaration */

// Initialize the webapp library and all connections.

void wa_init(wa_callback *);

// Reset the webapp library and all connections.

void wa_destroy(void);



//

#endif // ifdef _WA_H_



/* Where are the different servlet methods in our wa_request structure?

 * (Comparison between methods, CGI variables and wa_request pointers

 *

 *   c.getServerInfo()       SERVER_SOFTWARE         wa_callback->serverinfo()

 *   r.getProtocol()         SERVER_PROTOCOL         r->prot

 *   r.getMethod()           REQUEST_METHOD          r->meth

 *   r.getScheme()           -                       r->schm

 *   r.getQueryString()      QUERY_STRING            r->args

 *   r.getPathInfo()         PATH_INFO               -

 *   r.getPathTranslated()   PATH_TRANSLATED         -

 *   r.getServletPath()      SCRIPT_NAME             -

 *   r.isSecure()            -                       -

 *   r.getContentType()      CONTENT_TYPE            [header]

 *   r.getContentLength()    CONTENT_LENGTH          r->clen

 *   r.getServerName()       SERVER_NAME             r->name

 *   r.getServerPort()       SERVER_PORT             r->port

 *   r.getRemoteHost()       REMOTE_HOST             r->rhst

 *   r.getRemoteAddr()       REMOTE_ADDR             r->radr

 *   r.getRemoteUser()       REMOTE_USER             r->user

 *   r.getAuthType()         AUTH_TYPE               r->auth

 */

