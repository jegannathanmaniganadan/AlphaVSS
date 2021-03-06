
#pragma once

#include "VssWriterComponents.h"
#include "VssExamineWriterMetadata.h"
#include "Macros.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Threading::Tasks;
using namespace System::Threading;

namespace Alphaleonis { namespace Win32 { namespace Vss
{
   private ref class VssBackupComponents : IDisposable, IVssBackupComponents, MarshalByRefObject
   {
   public:
      VssBackupComponents();
      ~VssBackupComponents();
      !VssBackupComponents();

      virtual void AbortBackup();
      virtual void AddAlternativeLocationMapping(Guid writerId, VssComponentType componentType, String^ logicalPath, String^ componentName, String^ path, String^ filespec, bool recursive, String^ destination);
      virtual void AddComponent(Guid instanceId, Guid writerId, VssComponentType componentType, String^ logicalPath, String^ componentName);
      virtual void AddNewTarget(Guid writerId, VssComponentType componentType, String^ logicalPath, String^ componentName, String^ path, String^ fileName, bool recursive, String^ alternatePath);
      virtual void AddRestoreSubcomponent(Guid writerId, VssComponentType componentType, String^ logicalPath, String ^componentName, String^ subcomponentLogicalPath, String^ subcomponentName);

      virtual Guid AddToSnapshotSet(String^ volumeName, Guid providerId);
      virtual Guid AddToSnapshotSet(String^ volumeName);

      virtual void BackupComplete();
      virtual Task^ BackupCompleteAsync(CancellationToken cancellationToken);
      virtual IVssAsyncResult^ BeginBackupComplete(AsyncCallback^ userCallback, Object^ stateObject);
      virtual void EndBackupComplete(IAsyncResult ^asyncResult);      

      virtual void BreakSnapshotSet(Guid snapshotSetId);

      virtual void BreakSnapshotSet(Guid snapshotSetId, VssHardwareOptions breakFlags);
      virtual Task^ BreakSnapshotSetAsync(Guid snapshotSetId, VssHardwareOptions breakFlags, CancellationToken cancellationToken);
      virtual IVssAsyncResult^ BeginBreakSnapshotSet(Guid snapshotSetId, VssHardwareOptions breakFlags, AsyncCallback^ userCallback, Object^ stateObject);
      virtual void EndBreakSnapshotSet(IAsyncResult ^asyncResult);      

      virtual void DeleteSnapshot(Guid snapshotId, bool forceDelete);
      virtual int DeleteSnapshotSet(Guid snapshotSetId, bool forceDelete);

      virtual void DisableWriterClasses(array<Guid> ^ writerClassIds);
      virtual void DisableWriterInstances(array<Guid> ^ writerInstanceIds);
      
      virtual void DoSnapshotSet();
      virtual Task^ DoSnapshotSetAsync(CancellationToken cancellationToken);
      virtual IVssAsyncResult^ BeginDoSnapshotSet(AsyncCallback^ userCallback, Object^ stateObject);
      virtual void EndDoSnapshotSet(IAsyncResult ^asyncResult);      

      virtual void EnableWriterClasses(array<Guid> ^ writerClassIds);
      virtual String^ ExposeSnapshot(Guid snapshotId, String ^ pathFromRoot, VssVolumeSnapshotAttributes attributes, String ^ expose);
      virtual void FreeWriterMetadata();
      virtual void FreeWriterStatus();

      virtual void GatherWriterMetadata();
      virtual Task^ GatherWriterMetadataAsync(CancellationToken cancellationToken);
      virtual IVssAsyncResult^ BeginGatherWriterMetadata(AsyncCallback^ userCallback, Object^ stateObject);
      virtual void EndGatherWriterMetadata(IAsyncResult ^asyncResult);

      virtual void GatherWriterStatus();
      virtual Task^ GatherWriterStatusAsync(CancellationToken cancellationToken);
      virtual IVssAsyncResult^ BeginGatherWriterStatus(AsyncCallback^ userCallback, Object^ stateObject);
      virtual void EndGatherWriterStatus(IAsyncResult ^asyncResult);      

      virtual VssSnapshotProperties^ GetSnapshotProperties(Guid snapshotId);
      property IList<IVssWriterComponents^>^ WriterComponents { virtual IList<IVssWriterComponents^>^ get(); }
      property IList<IVssExamineWriterMetadata^>^ WriterMetadata { virtual IList<IVssExamineWriterMetadata^>^ get(); }
      property IList<VssWriterStatusInfo^>^ WriterStatus { virtual IList<VssWriterStatusInfo^>^ get(); }
      
      virtual void ImportSnapshots();
      virtual Task^ ImportSnapshotsAsync(CancellationToken cancellationToken);
      virtual IVssAsyncResult^ BeginImportSnapshots(AsyncCallback^ userCallback, Object^ stateObject);
      virtual void EndImportSnapshots(IAsyncResult ^asyncResult);      

      virtual void InitializeForBackup(String^ xml);
      virtual void InitializeForRestore(String^ xml);
      virtual bool IsVolumeSupported(String^ volumeName, Guid providerId);
      virtual bool IsVolumeSupported(String^ volumeName);
      
      virtual void PostRestore();
      virtual Task^ PostRestoreAsync(CancellationToken cancellationToken);
      virtual IVssAsyncResult^ BeginPostRestore(AsyncCallback^ userCallback, Object^ stateObject);
      virtual void EndPostRestore(IAsyncResult ^asyncResult);      
      
      virtual void PrepareForBackup();
      virtual Task^ PrepareForBackupAsync(CancellationToken cancellationToken);
      virtual IVssAsyncResult^ BeginPrepareForBackup(AsyncCallback^ userCallback, Object^ stateObject);
      virtual void EndPrepareForBackup(IAsyncResult ^asyncResult);      
      
      virtual void PreRestore();
      virtual Task^ PreRestoreAsync(CancellationToken cancellationToken);
      virtual IVssAsyncResult^ BeginPreRestore(AsyncCallback^ userCallback, Object^ stateObject);
      virtual void EndPreRestore(IAsyncResult ^asyncResult);      

      virtual System::Collections::Generic::IEnumerable<VssSnapshotProperties^> ^QuerySnapshots();
      virtual System::Collections::Generic::IEnumerable<VssProviderProperties^> ^QueryProviders();
      
      virtual IVssAsyncResult^ BeginQueryRevertStatus(String^ volumeName, AsyncCallback^ userCallback, Object^ stateObject);
      virtual Task^ QueryRevertStatusAsync(String^ volumeName, CancellationToken cancellationToken);
      virtual void EndQueryRevertStatus(IAsyncResult ^asyncResult);


      virtual void RevertToSnapshot(Guid snapshotId, bool forceDismount);
      virtual String^ SaveAsXml();
      virtual void SetAdditionalRestores(Guid writerId, VssComponentType componentType, String^ logicalPath, String^ componentName, bool additionalResources);
      virtual void SetAuthoritativeRestore(Guid writerId, VssComponentType componentType, String^ logicalPath, String^ componentName, bool isAuthorative);
      virtual void SetBackupOptions(Guid writerId, VssComponentType componentType, String^ logicalPath, String^ componentName, String^ backupOptions);
      virtual void SetBackupState(bool selectComponents, bool backupBootableSystemState, VssBackupType backupType, bool partialFileSupport);
      virtual void SetBackupSucceeded(Guid instanceId, Guid writerId, VssComponentType componentType, String^ logicalPath, String^ componentName, bool succeeded);
      virtual void SetContext(VssVolumeSnapshotAttributes context);
      virtual void SetContext(VssSnapshotContext context);
      virtual void SetFileRestoreStatus(Guid writerId, VssComponentType componentType, String^ logicalPath, String^ componentName, VssFileRestoreStatus status);
      virtual void SetPreviousBackupStamp(Guid writerId, VssComponentType componentType, String^ logicalPath, String^ componentName, String^ previousBackupStamp);
      virtual void SetRangesFilePath(Guid writerId, VssComponentType componentType, String^ logicalPath, String^ componentName, int partialFileIndex, String^ rangesFile);
      virtual void SetRestoreName(Guid writerId, VssComponentType componentType, String^ logicalPath, String^ componentName, String^ restoreName);
      virtual void SetRestoreOptions(Guid writerId, VssComponentType componentType, String^ logicalPath, String^ componentName, String^ restoreOptions);
      virtual void SetRestoreState(VssRestoreType restoreType);
      virtual void SetRollForward(Guid writerId, VssComponentType componentType, String^ logicalPath, String^ componentName, VssRollForwardType rollType, String^ rollForwardPoint);
      virtual void SetSelectedForRestore(Guid writerId, VssComponentType componentType, String^ logicalPath, String^ componentName, bool selectedForRestore);
      virtual void SetSelectedForRestore(Guid writerId, VssComponentType componentType, String^ logicalPath, String^ componentName, bool selectedForRestore, Guid instanceId);

      virtual Guid StartSnapshotSet();
      virtual void UnexposeSnapshot(Guid snapshotId);

      virtual Guid GetSessionId(); 
      virtual void AddSnapshotToRecoverySet(Guid snapshotId, String^ destinationVolume);
      
      virtual void RecoverSet(VssRecoveryOptions options);
      virtual Task^ RecoverSetAsync(VssRecoveryOptions options, CancellationToken cancellationToken);
      virtual IVssAsyncResult^ BeginRecoverSet(VssRecoveryOptions options, AsyncCallback^ userCallback, Object^ stateObject);
      virtual void EndRecoverSet(IAsyncResult ^asyncResult);      

      virtual VssRootAndLogicalPrefixPaths^ GetRootAndLogicalPrefixPaths(String^ filePath, bool normalizeFQDNforRootPath);

   private:
      ::IVssBackupComponents *m_backup;

      DEFINE_EX_INTERFACE_ACCESSOR(IVssBackupComponentsEx, m_backup)
      DEFINE_EX_INTERFACE_ACCESSOR(IVssBackupComponentsEx2, m_backup)
      DEFINE_EX_INTERFACE_ACCESSOR(IVssBackupComponentsEx3, m_backup)
      DEFINE_EX_INTERFACE_ACCESSOR(IVssBackupComponentsEx4, m_backup)

      ref class WriterMetadataList : VssListAdapter<IVssExamineWriterMetadata^>
      {
      public:
         WriterMetadataList(VssBackupComponents^ backupComponents);

         property int Count { virtual int get() override; }
         property IVssExamineWriterMetadata^ default[int] { virtual IVssExamineWriterMetadata^ get(int index) override; }
      private:
         VssBackupComponents^ m_backupComponents;
      };


      ref class WriterComponentsList : VssListAdapter<IVssWriterComponents^>
      {
      public:
         WriterComponentsList(VssBackupComponents^ backupComponents);

         property int Count { virtual int get() override; }
         property IVssWriterComponents^ default[int] { virtual IVssWriterComponents^ get(int index) override; }
      private:
         VssBackupComponents^ m_backupComponents;
      };

      ref class WriterStatusList : VssListAdapter<VssWriterStatusInfo^>
      {
      public:
         WriterStatusList(VssBackupComponents^ backupComponents);

         property int Count { virtual int get() override; }
         property VssWriterStatusInfo^ default[int] { virtual VssWriterStatusInfo^ get(int index) override; }
      private:
         VssBackupComponents^ m_backupComponents;
      };

      WriterMetadataList^ m_writerMetadata;
      WriterComponentsList^ m_writerComponents;
      WriterStatusList^ m_writerStatus;
   };


}
} }
