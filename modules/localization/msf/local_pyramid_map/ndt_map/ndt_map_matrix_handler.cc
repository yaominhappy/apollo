/******************************************************************************
 * Copyright 2019 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/
#include "modules/localization/msf/local_map/ndt_map/ndt_map_matrix_handler.h"

namespace apollo {
namespace localization {
namespace msf {
// =================PyramidMapMatrixHandlerSelector=================
NdtMapMatrixHandlerSelector::NdtMapMatrixHandlerSelector() {}

NdtMapMatrixHandlerSelector::~NdtMapMatrixHandlerSelector() {}

BaseMapMatrixHandler* NdtMapMatrixHandlerSelector::AllocNdtMapMatrixHandler() {
  return new NdtMapMatrixHandler();
}

NdtMapMatrixHandler::NdtMapMatrixHandler() {}
NdtMapMatrixHandler::~NdtMapMatrixHandler() {}

size_t NdtMapMatrixHandler::LoadBinary(const unsigned char* buf,
                                       BaseMapMatrix* matrix) {
  if (!matrix) {
    return 0;
  }
  NdtMapMatrix* ndt_matrix = dynamic_cast<NdtMapMatrix*>(matrix);
  size_t size = ndt_matrix->LoadBinary(buf);
  return size;
}
/**@brief Create the binary. Serialization of the object.
 * @param <buf, buf_size> The buffer and its size.
 * @param <return> The required or the used size of is returned.
 */
size_t NdtMapMatrixHandler::CreateBinary(const BaseMapMatrix* matrix,
                                         unsigned char* buf,
                                         size_t buf_size) {
  if (!matrix) {
    return 0;
  }
  const NdtMapMatrix* ndt_matrix = dynamic_cast<const NdtMapMatrix*>(matrix);
  return ndt_matrix->CreateBinary(buf, buf_size);
}
/**@brief Get the binary size of the object. */
size_t NdtMapMatrixHandler::GetBinarySize(const BaseMapMatrix* matrix) {
  const NdtMapMatrix* ndt_matrix = dynamic_cast<const NdtMapMatrix*>(matrix);
  return ndt_matrix->GetBinarySize();
}

}  // namespace msf
}  // namespace localization
}  // namespace apollo
