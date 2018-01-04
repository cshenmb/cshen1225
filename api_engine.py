import casface

from ph_engine.image_recognizer_helper.video_recognizer import VideoRecognizer

class api_engine(object):

    def __init__(self, engine_id, local_vpath_name, RECOG_CONFIDENCE):
        self.engine_id = engine_id
        self.local_vpath_name = local_vpath_name
        self.RECOG_CONFIDENCE = RECOG_CONFIDENCE

    def ret_from_api(self):

        if self.engine_id == 90:
            ret_from_cas_api = casface.recog_face_fromvideo(self.local_vpath_name, self.RECOG_CONFIDENCE)
            return ret_from_cas_api
        elif self.engine_id == 1:
            recognizer = VideoRecognizer(debug=False, need_delete_tmp_image_dir=True) 
            video_path = os.path.expanduser(self.local_vpath_name)
            place_results = recognizer.recognize_place(video_path)

            results_dict={"conThre":0.6000000238418579,"frameRate":25.0,
                          "modInfo":"v0.0.0","modName":"facetrack170313.bin, ldmk.bin, fea.bin ",
                          "processTime":178.3849792480469,
                          "resultList":[]
                         }

            for x in place_results:
                resultList = {}
                resultList['name'] = x['scene_place']['name']
                #default id =0
                resultList['id'] = 0
                resultList['confidence'] = x['scene_place']['score']
                resultList['startframe'] = x['scene_start_frame_number']
                resultList['endframe'] = x['scene_end_frame_number']
                resultList['positionlist'] = []
                frame_rate = x['video_framerate']
                results_dict['resultList'].append(resultList)
                print(x)
            results_json['frameRate'] = frame_rate
            ret_from_cas_api = [0, results_json]

            
            return ret_from_cas_api

if __name__=='__main__':
    ret_from_cas_api=api_engine(1, 'http://218.241.154.237:8081/files/fileslocal/zhaoliying.mp4', 0.6)
    print(ret_from_cas_api.ret_from_api()[0])
    print(ret_from_cas_api.ret_from_api()[1])

