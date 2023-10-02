load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
  name = "com_google_googletest",
  urls = ["https://github.com/google/googletest/archive/7e33b6a1c497ced1e98fc60175aeb4678419281c.zip"],
  strip_prefix = "googletest-7e33b6a1c497ced1e98fc60175aeb4678419281c",
)

local_repository(
    name = "bazel_sonarqube",
    path = "bazel-sonarqube",
)

load("@bazel_sonarqube//:repositories.bzl", "bazel_sonarqube_repositories")

bazel_sonarqube_repositories()