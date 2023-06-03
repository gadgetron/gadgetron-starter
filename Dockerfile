# Shared arguments
ARG USERNAME="vscode"
ARG USER_UID=1000
ARG USER_GID=$USER_UID

FROM ghcr.io/gadgetron/gadgetron/gadgetron_ubuntu_dev_cuda:latest AS gadgetron_dev_cuda

ARG USERNAME
ARG USER_UID
ARG USER_GID
ARG HOME=/home/$USERNAME

# Copy environment, which will be filtered for later staged
COPY --chown=$USER_UID:conda environment.yml /tmp/build/oot_environment.yml

FROM gadgetron_dev_cuda AS gadgetron_dev_cuda_oot
ARG USER_UID
USER ${USER_UID}
RUN umask 0002 && /opt/conda/bin/conda env update -f /tmp/build/oot_environment.yml && /opt/conda/bin/conda clean -afy && sudo chown -R :conda /opt/conda
USER root

FROM gadgetron_dev_cuda_oot AS gadgetron_cudabuild_oot
ARG USER_UID
ARG USER_GID
USER ${USER_UID}
WORKDIR /opt
RUN sudo chown $USER_UID:$USER_GID /opt && mkdir -p /opt/code/gadgetron-starter && mkdir -p /opt/package
COPY --chown=$USER_UID:conda . /opt/code/gadgetron-starter/
SHELL ["/bin/bash", "-c"]
RUN . /opt/conda/etc/profile.d/conda.sh && umask 0002 && conda activate gadgetron && sh -x && \
    cd /opt/code/gadgetron-starter && \
    sudo mkdir /opt/intel &&\
    sudo mkdir /opt/intel/mkl &&\
    sudo mkdir /opt/intel/mkl/lib &&\
    sudo mkdir /opt/intel/mkl/lib/intel64 &&\
    sudo ln -s /opt/conda/envs/gadgetron/lib/libmkl_intel_lp64.so /opt/intel/mkl/lib/intel64/libmkl_intel_lp64.so && \
    sudo ln -s /opt/conda/envs/gadgetron/lib/libmkl_gnu_thread.so /opt/intel/mkl/lib/intel64/libmkl_gnu_thread.so && \
    sudo ln -s /opt/conda/envs/gadgetron/lib/libmkl_core.so /opt/intel/mkl/lib/intel64/libmkl_core.so && \
    mkdir build && \
    cd build && \
    cmake ../ -GNinja -DUSE_MKL=ON -DCMAKE_INSTALL_PREFIX=/opt/package && \
    ninja && \
    ninja install

FROM ghcr.io/gadgetron/gadgetron/gadgetron_ubuntu_rt_cuda:latest AS gadgetron_rt_cuda
ARG USER_UID
USER ${USER_UID}
COPY --from=gadgetron_cudabuild_oot --chown=$USER_UID:conda /opt/package /opt/conda/envs/gadgetron/
ENTRYPOINT [ "/tini", "--", "/opt/entrypoint.sh" ]
