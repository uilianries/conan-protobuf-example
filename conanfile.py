import os
from conans import ConanFile, CMake


class ProtobufexampleConan(ConanFile):
    name = "protobuf-example"
    version = "0.1"
    settings = "os", "compiler", "build_type", "arch"
    generators = "cmake"
    requires = ("protoc_installer/3.6.1@bincrafters/stable", "protobuf/3.6.1@bincrafters/stable")
    scm = {
         "type": "git",
         "url": "auto",
         "revision": "auto"
    }

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        self.copy("sensor", dst="bin", src="bin")

    def package_info(self):
        self.env_info.PATH.append(os.path.join(self.package_folder, "bin"))
